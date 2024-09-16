//
// Created by dominykas on 13-11-23.
//

#ifndef TEST_FEATURES_H
#define TEST_FEATURES_H

#include "Item.h"
#include "Shapes/Shapes.h"
#include "../Controls/Camera.h"

namespace Features{
    struct View{
        glm::mat4 perspective;
        glm::mat4 view;
        glm::mat4 projection;
    };
    struct free_delete
    {
        void operator()(void* x) { std::cout << "del\n";free(x); }
    };
    //Initializes Camera with predefined settings
    Camera GetCamera(){
        return {vec4(0, 0, -5, 0)};
    }
    //initializes selected items
    Item* Initialize_Features(){
        Item item;

        std::shared_ptr<float> ptr((float*)malloc(sizeof(float)*Object::sphere1.v_size), free_delete());
        std::shared_ptr<unsigned int> ptrE((unsigned int*)malloc(sizeof(unsigned int)*Object::sphere1.ebo_size), free_delete());

        memcpy(ptr.get(), Object::sphere1.vertices, sizeof(float)*Object::sphere1.v_size);
        memcpy(ptrE.get(), Object::sphere1.EBO, sizeof(float)*Object::sphere1.ebo_size);


        Item* items = (Item*)malloc(sizeof(Item)*4);
     /*   int index = 0;
        for(int j = 1; j <= 30; j ++){
            for(int i = 1; i<= 30; i ++){
                items[index] = {ptr, (int)sizeof(float)*(Object::sphere1.v_size), ptrE, (int)sizeof(float)*Object::sphere1.ebo_size};
                glm::vec3 rax = glm::vec3 (1,  0, 0);
                items[index].axis = rax;
                items[index].position = glm::vec3 (10*(i-5), 10*(j-5), -600);
                items[index].mass = 2;
                items[index].velocity = (float)1*(cross(vec3((i-5),(j-5) , 0), vec3(0, 0, 1)));
                items[index].velocity.z = 0;
                index ++;
            }
        }*/

        items[1] = {ptr, (int)sizeof(float)*(Object::sphere1.v_size), ptrE, (int)sizeof(float)*Object::sphere1.ebo_size};
        items[0] = {ptr, (int)sizeof(float)*(Object::sphere1.v_size), ptrE, (int)sizeof(float)*Object::sphere1.ebo_size};
        items[2] = {ptr, (int)sizeof(float)*(Object::sphere1.v_size), ptrE, (int)sizeof(float)*Object::sphere1.ebo_size};
        items[3] = {ptr, (int)sizeof(float)*(Object::sphere1.v_size), ptrE, (int)sizeof(float)*Object::sphere1.ebo_size};
        glm::vec3 rax = glm::vec3 (1,  0, 0);
        items[0].axis = rax;
        items[0].position = glm::vec3 (0, 4, -0);
        items[0].Scale(1);
        items[0].mass = 20000;
        items[1].mass = 20000;
        items[1].axis = rax;
        items[1].position = glm::vec3 (0, -4, -0);
        items[1].velocity = glm::vec3(-0, 0, 0);
        items[0].velocity = glm::vec3(1, 0, 0);
        items[2].axis =rax;
        items[2].position = glm::vec3 (-1, 1, -0);
        items[3].axis = rax;
        items[3].position = glm::vec3 (-1, -1, -0);
        return items;
    }

    Item* Initialize_Points(std::shared_ptr<float> *array, unsigned int** VAOs, unsigned int** VBO, unsigned int** EBO){
        Item item;

        std::shared_ptr<unsigned int> ptrE((unsigned int*)malloc(sizeof(unsigned int)*1), free_delete());
        ptrE.get()[0] = 0;

        *VAOs = (unsigned int*)malloc(sizeof(unsigned int)*100);
        *VBO = (unsigned int*)malloc(sizeof(unsigned int)*100);
        *EBO = (unsigned int*)malloc(sizeof(unsigned int)*100);

        glGenVertexArrays(100, *VAOs);
        glGenBuffers(100, *VBO);
        glGenBuffers(100, *EBO);
        Item* items = (Item*)malloc(sizeof(Item)*100);
        int index = 0;
        for(int j = 1; j <= 10; j ++){
            for(int i = 1; i<= 10; i ++){

                glm::vec3 posit = glm::vec3((i-15), (j-15), 0);
                array[index] = std::shared_ptr<float>((float*)malloc(sizeof(float)*3), free_delete());
                array[index].get()[0] = posit.x;
                array[index].get()[1] = posit.y;
                array[index].get()[2] =  0.0f;
                items[index] = {&array[index], (int)sizeof(float)*(3), ptrE, (int)sizeof(float)*1, VAOs, VBO, EBO, index};
                items[index].mass = 1;
                //items[index].position.x = posit.x;
                index ++;
            }
        }
        for(int k = 0; k < 100; k ++){
            std::cout << "inputing : " << items[k].vertices.array->get()[0]<< " " << items[k].vertices.array->get()[1] << "\n";
        }
        return items;
    }
    //Creates view and perspective matrices


    View CreateViewModel(){
        glm::mat4 view = glm::mat4(1.0f);
        view[3][2] = -0.0f;
        return {glm::mat4(1.0f), view,  glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100000.0f)};
    }
}
#endif //TEST_FEATURES_H
