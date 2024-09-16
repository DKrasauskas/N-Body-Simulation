//
// Created by dominykas on 9-10-23.
//
#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Render.h"

Render::Render(unsigned int& program) {
   this->program = program;
}
glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
};

void Render::Run(unsigned int& VAO) {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program);
    int loc = glGetUniformLocation(program, "transform");
    glBindVertexArray(VAO);
    //glDrawArrays(GL_TRIANGLES, 0, 6);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
float rot = 0;
void Render::Run(unsigned int& VAO, glm::mat4& view, glm::mat4& projection, glm::mat4& model, GLFWwindow *window) {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program);

    int loc = glGetUniformLocation(program, "projection");
    glUniformMatrix4fv(loc,1, GL_FALSE, glm::value_ptr(projection));
    loc = glGetUniformLocation(program, "view");
    glUniformMatrix4fv(loc,1, GL_FALSE, glm::value_ptr(view));
    glBindVertexArray(VAO);
    for(int i = 0; i < 10; i ++){
        model = glm::mat4(1.0f);
        model = glm::translate(model, cubePositions[i]);
        model = glm::rotate(model, glm::radians(rot), glm::vec3(0.5f, 1.0f, 0.5f));
        rot += 0.1;
        loc = glGetUniformLocation(program, "model");

        glUniformMatrix4fv(loc,1, GL_FALSE, glm::value_ptr(model));

        //view = glm::translate(view, glm::vec3(0.001f, 0.0f, 0.0f));

        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS){
        view = glm::translate(view, glm::vec3(0.0f, 0.05f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
        view = glm::translate(view, glm::vec3(0.0f, -0.05f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS){
        view = glm::translate(view, glm::vec3(0.05f, 0.0f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS){
        view = glm::translate(view, glm::vec3(-0.05f, 0.0f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, 0.05f));
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -0.05f));
    }


    //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}