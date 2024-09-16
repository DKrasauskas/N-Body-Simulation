//
// Created by dominykas on 9-10-23.
//
#include "../../GLFW/glm/glm.hpp"
#include "../../GLFW/glm/gtc/matrix_transform.hpp"
#include "../../GLFW/glm/gtc/type_ptr.hpp"
#include "../Objects/Item.h"
#include "../Controls/Camera.h"


#ifndef TEST_RENDER_H
#define TEST_RENDER_H


class Render {
public:
     explicit Render(unsigned int& program);
     explicit Render(){};
     unsigned int program, Cprogram;
     void Run(unsigned int& VAO) const;
     void Run(unsigned int* VAO,glm::mat4& view, glm::mat4& projection, glm::mat4& model, GLFWwindow* window);
     void Run(Camera& camera, Item* items,int size, glm::mat4& view, glm::mat4& projection, glm::mat4& model, GLFWwindow* window, GLFWcursor* cursor);
     void Runs( unsigned int& VAO, Camera& camera, glm::mat4& view, glm::mat4& projection, glm::mat4& model, GLFWwindow* window, GLFWcursor* cursor);
     void RunControls(Camera& camera, glm::mat4& view, glm::mat4& projection, glm::mat4& model, GLFWwindow* window, GLFWcursor* cursor);
     //for communication with GLSL
     void Send(const char* var_name, glm::mat4 variable);
     void Send(const char* var_name, glm::vec3 variable);
     void Send(const char* var_name, glm::vec4 variable);
};


#endif //TEST_RENDER_H
