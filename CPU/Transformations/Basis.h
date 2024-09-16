//
// Created by dominykas on 12-11-23.
//
#pragma once
#ifndef TEST_BASIS_H
#define TEST_BASIS_H
#include "../../GLFW/glm/glm.hpp"
#include "../../GLFW/glm/gtc/matrix_transform.hpp"
#include "../../GLFW/glm/gtc/type_ptr.hpp"

using namespace glm;
class Basis {
public:
    mat4 basis = mat4(1);
    explicit Basis();
    //Basis(mat4 custom_basis);
    explicit Basis(vec3 x, vec3 y, vec3 z);
};
namespace Transform{
    void Rotate(Basis& origin, vec4& axis);
    vec3 Rotates(vec3 origin, vec4 axis);
};

#endif //TEST_BASIS_H
