//
// Created by dominykas on 28-9-23.
//

#ifndef TEST_SHADER_H
#define TEST_SHADER_H
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../../Glad/glad.h"
#include "../../GLFW/GLFW/glfw3.h"

using namespace std;

class Shader {
public:
    unsigned int ID, PID;
    Shader(const char* inputVertex, const char* inputFragment);
    Shader(const char* inputVertex, const char* inputFragment, const char* inputCompute);
    Shader(){};
    char* Parse(string input);
    void BuildShaders(unsigned int &shader, const char* source, uint32_t shader_type);
    void Link(unsigned int&program);
};
#endif //TEST_SHADER_H
