//
// Created by dominykas on 9-10-23.
//
#include <stuff/glm/glm/glm.hpp>
#include <stuff/glm/glm/gtc/matrix_transform.hpp>
#include <stuff/glm/glm/gtc/type_ptr.hpp>
#ifndef TEST_RENDER_H
#define TEST_RENDER_H


class Render {
public:
     explicit Render(unsigned int& program);
     unsigned int program;
     void Run(unsigned int& VAO);
     void Run(unsigned int& VAO, glm::mat4& view, glm::mat4& projection, glm::mat4& model, GLFWwindow* window);
};


#endif //TEST_RENDER_H
