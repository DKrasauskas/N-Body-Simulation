//
// Created by dominykas on 4-11-23.
//

#ifndef TEST_SHAPES_H
#define TEST_SHAPES_H
#pragma once
#include <iostream>
#include "../../../Glad/glad.h"
#include "../../../GLFW/GLFW/glfw3.h"
#include <cmath>

struct Sphere{
    float* vertices;
    int v_size, ebo_size;
    unsigned int* EBO;
    Sphere(float* vertices, int v_size, int ebo_size, unsigned int* EBO){
        this->vertices = vertices;
        this->v_size = v_size;
        this->ebo_size = ebo_size;
        this->EBO = EBO;
    }
    Sphere(){}
};

namespace Object{
   extern Sphere sphere1;
}

class Shapes {
public:
    static void GenerateCube(int rez, float** src, int& index, unsigned int** EBO, int& eb);
    static void GenerateSphere(int rez, float** src, int& index, unsigned int** EBO, int& eb);
    static void GenerateCube(int rez, bool convert_to_sphere);
    static void GenerateSphere(int rez);
    static void Offset(float x, float y, float z);
    static void ToSphere(float* arr, int size);

};

#endif //TEST_SHAPES_H
