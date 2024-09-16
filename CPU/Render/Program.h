//
// Created by dominykas on 1-11-23.
//

#ifndef TEST_PROGRAM_H
#define TEST_PROGRAM_H
#pragma once
#include "../../GPU/Shaders/Shader.h"
#include "Render.h"
#include "../Objects/Obj/Obj.h"

namespace Program{
    Shader shader;
    Render render;

    void Start(){
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        //glfwWindowHint(GLFW_SAMPLES, 4);
        Window();
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
        Glad();
        //glEnable(GL_MULTISAMPLE);
    }
    void Begin(){
        Start();
        shader = {  ("C:/Users/domin/CLionProjects/ComputeShaderPhysics/GPU/Shaders/Vertex.glsl"),
                  ("C:/Users/domin/CLionProjects/ComputeShaderPhysics/GPU/Shaders/Fragment.glsl"),
                  ("C:/Users/domin/CLionProjects/ComputeShaderPhysics/GPU/ExtShaders/Compute.glsl") };
        render = Render(Program::shader.ID);
        render.Cprogram = Program::shader.PID;
       // glUseProgram(Program::shader.ID);
    }

    /*
     * Below are functions for generating VAO's and VBO's. This has been superseded by members of the Item class
     */
    //DEPRECATED
    void GenVaOB(unsigned int &VAO, unsigned int &VBO,unsigned int &EBO, ElementaryShapes::Element element){
        glBindVertexArray(0);
        glGenBuffers(1, &EBO);
        GenVAO(VAO,VBO, element.indices, element.size);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, element.ebosize, element.ebo, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, element.step *4, (void*)0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, element.step *4, (void*)0);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        //glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, element.step * 4, (void*)(3*sizeof(float)));
        // glEnableVertexAttribArray(1);
    }
    //DEPRECATED
    void GenVaOBS(unsigned int *VAOs, unsigned int *VBOs, unsigned int* EBOs, int v_size, int e_size, ElementaryShapes::Element* element){
        glBindVertexArray(0);
        glGenBuffers(1, &(EBOs[0]));
        GenVAO(VAOs[0],VBOs[0], element[0].indices, element[0].size);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[0]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, element[0].ebosize, element[0].ebo, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, element[0].step *4, (void*)0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, element[0].step *4, (void*)0);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        //glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, element.step * 4, (void*)(3*sizeof(float)));
        // glEnableVertexAttribArray(1);
    }
    //DEPRECATED
    void GenVaOBSs(unsigned int *VAOs, unsigned int *VBOs, unsigned int* EBOs, int v_size, int e_size, ElementaryShapes::Element* element){
        glGenVertexArrays(v_size, VAOs);
        glGenBuffers(v_size, VBOs);
        for(int i = 0; i < v_size; i ++){
            glBindVertexArray(VAOs[i]);
            glBindBuffer(GL_ARRAY_BUFFER, VBOs[i]);
            glBufferData(GL_ARRAY_BUFFER, element[i].size, element[i].indices, GL_STATIC_DRAW);
            glGenBuffers(1, &(EBOs[i]));
            glBindVertexArray(VAOs[i]);
            glBindBuffer(GL_ARRAY_BUFFER, VBOs[i]);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[i]);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, element[i].ebosize, element[i].ebo, GL_STATIC_DRAW);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 4 * element[i].step, (void*)0);	// Vertex attributes stay the same
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, element[i].step * 4, (void*)(0));
            glEnableVertexAttribArray(0);
            glEnableVertexAttribArray(1);
        }

    }
    //DEPRECATED
    void GenVaOB(unsigned int &VAO, unsigned int &VBO, ElementaryShapes::Element element){
        glBindVertexArray(0);
        // GenVAO(VAO, VBO, EBO, Kubs, 36, indices2, sizeof(indices2));
        GenVAO(VAO,VBO, element.indices, element.size);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, element.step *4, (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, element.step * 4, (void*)(3*sizeof(float)));
        glEnableVertexAttribArray(1);
    }


}
#endif //TEST_PROGRAM_H
