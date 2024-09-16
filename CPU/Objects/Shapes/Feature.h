//
// Created by dominykas on 16-11-23.
//
#pragma once
#ifndef TEST_FEATURE_H
#define TEST_FEATURE_H
#include <memory>
#include <iostream>
#include "../../../Glad/glad.h"
#include "../../../GLFW/GLFW/glfw3.h"
#include <cstring>
template <typename T>
struct Arrays{
    T array;
    unsigned int size;
};
class Feature {
public:
    Arrays<float*> vertex_array;
    Arrays<unsigned int*> indices_array;
    Feature(float* vertices, unsigned int size, unsigned int* EBO, unsigned int i_size);

};


#endif //TEST_FEATURE_H
