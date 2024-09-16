#pragma once
#include <iostream>
#include "glad/glad.h"
#include "GLFW/GLFW/glfw3.h"
#include "utils/parser.h"
#include "utils/Vertices.h"
#include "config/Window.h"
#include "CPU/Objects/Obj/ElementaryShapes.h"
#include "CPU/Objects/Shapes/Shapes.h"
#include "CPU/Render/Program.h"
//#include "CPU/Objects/Item.h"
#include "CPU/Objects/Features.h"
#include "CPU/Objects/Shapes/Feature.h"
#include "GLFW/glm/glm.hpp"
#include "GLFW/glm/gtc/matrix_transform.hpp"
#include "GLFW/glm/gtc/type_ptr.hpp"

// Item objects

/*
 * This is the main file of the program.
 * Change Window parameters in Window.h, but beware stretching due to different AR
 * Define renderable objects, such as camera or simple geometric objects in Features.h
 */


namespace Globals{
    struct GLobalVertexAttributes{
        unsigned int VAO, VBO, EBO;
        float* vertices;
        unsigned int * indices;
        unsigned int size, i_size, max_size, max_isize;
        void INIT(){
            if((vertices = (float*)malloc(sizeof(float)*9))== nullptr){
                throw;
            }
            max_size = 9;
            size = 0;
            if((indices = (unsigned int*)malloc(sizeof(unsigned int)*3))== nullptr){
                throw;
            }
            max_isize = 3;
            i_size = 0;
        }
        void GenerateVAO(){
            glGenVertexArrays(1, &VAO);
            glBindVertexArray(VAO);
            glGenBuffers(1, &VBO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(float)*size, vertices, GL_STATIC_DRAW);
            glGenBuffers(1, &(EBO));
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, (int)i_size*sizeof(unsigned int), indices, GL_STATIC_DRAW);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 4 * 3, (void*)0);	// Vertex attributes stay the same
            glEnableVertexAttribArray(0);
        }
        void Append(Feature& feature){
            if((size + feature.vertex_array.size) >= max_size){
                max_size *= 2;
                std::cout << max_size << "\n";
                vertices = (float*) realloc(vertices, sizeof(float)*max_size);
                max_isize *= 2;
                indices = (unsigned int*) realloc(indices, sizeof(unsigned int)*max_isize);
            }
            memcpy(vertices+size, feature.vertex_array.array, sizeof(float)*feature.vertex_array.size);
            memcpy(indices+i_size, feature.indices_array.array, sizeof(float)*feature.indices_array.size);
            size += feature.vertex_array.size;
            i_size += feature.indices_array.size;
        }
        void Destruct(){
            free(vertices);
            free(indices);
        }
    };
    Feature* GetFeatures(int count){
        Feature* features = (Feature*)malloc(sizeof(Feature)*count*count);
        int index =0;
        for(int j = 0; j < count; j ++){
            for(int i = 0; i < count; i++){
                float vertices[3] = {(float)((float)i - (float)count/2)/10, (float)((float)j-(float)count/2)/10, 0};
                unsigned int indices[1] = {(unsigned int)index};
                features[index] = {vertices, 3, indices, 1 };
                index++;
            }
        }
        return features;
    }
}

using namespace std;
using namespace glm;
void GenerateVertexArrays(unsigned int* arrays, int count){
    glGenVertexArrays(count, arrays);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
}
int main()
{
    Camera camera = Features::GetCamera();
    Shapes::GenerateCube(1, 1);

    Program::Begin();
    int size = 200;
    int ksize = size*size;
    Feature* features = Globals::GetFeatures(size);
    Globals::GLobalVertexAttributes structure;
    structure.INIT();

    for(int i = 0; i < ksize; i++){
        structure.Append(features[i]);
    }

    structure.GenerateVAO();
    struct Position{
        vec4 pos;
    };
    Position* positions = (Position*)malloc(sizeof(Position) * size * size);
    int index = 0;
    for(int i = 0; i < size*size*3; i += 3){
        positions[index].pos.x = structure.vertices[i];
        positions[index].pos.y = structure.vertices[i +  1];
        vec3 u = cross(glm::vec3(0, 0, 1), glm::vec3( structure.vertices[i],  structure.vertices[i+1], 0));
        positions[index].pos.z = 0.2f *u.x ;
        positions[index].pos.w = 0.2f * u.y ;
        index++;
    }
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    Features::View mode = Features::CreateViewModel();
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    GLFWcursor* cursor = glfwCreateStandardCursor(GLFW_HRESIZE_CURSOR);
    glfwSetCursor(window, cursor);
    GLuint ssbo, vssbo;
    glGenBuffers(1, &ssbo);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, ssbo);
    glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(Position)*size*size, positions, GL_STATIC_DRAW); //sizeof(data) only works for statically sized C/C++ arrays.
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 3, ssbo);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
    glGenBuffers(1, &vssbo);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, vssbo);
    glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(Position)*size*size, positions, GL_STATIC_DRAW); //sizeof(data) only works for statically sized C/C++ arrays.
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 4, vssbo);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
    GLint a;
    glGetIntegerv(GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS, &a);
    cout << "GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS: " << a << endl;
    free(positions);
    while (!glfwWindowShouldClose(window))
    {
        // Callback on keyboard/mouse inputs
        processInput(window);
       // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // render
        Program::render.Runs(structure.VAO, camera, mode.view, mode.projection, mode.perspective, window, cursor);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    structure.Destruct();
    for(int i = 0 ; i < ksize; i ++){
        free(features[i].vertex_array.array);
        free(features[i].indices_array.array);
    }
   // structure.Destruct();
   /* unsigned int* VAOs;
    unsigned int* VBOs;
    unsigned int* EBOs;
    std::shared_ptr<float> array[100];
    Item* items = Features::Initialize_Points(array, &VAOs, &VBOs, &EBOs);
    for(int k = 0; k < 100; k ++){
        std::cout << "inputingSS : " << items[k].vertices.array->get()[0]<< " " << items[k].vertices.array->get()[1] << "\n";
    }*/
   /* Features::View mode = Features::CreateViewModel();

    //Change between wireframe mode and textures
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glEnable(GL_DEPTH_TEST);

    GLFWcursor* cursor = glfwCreateStandardCursor(GLFW_HRESIZE_CURSOR);
    glfwSetCursor(window, cursor);



    while (!glfwWindowShouldClose(window))
    {
        // Callback on keyboard/mouse inputs
        processInput(window);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // render
        Program::render.Run(camera, items, 100, mode.view, mode.projection, mode.perspective, window, cursor);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();*/
    return 0;
}

