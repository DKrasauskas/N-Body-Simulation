//
// Created by dominykas on 11-11-23.
//
#pragma once
#ifndef TEST_CAMERA_H
#define TEST_CAMERA_H
#include "../../GLFW/glm/glm.hpp"
#include "../../GLFW/glm/gtc/matrix_transform.hpp"
#include "../../GLFW/glm/gtc/type_ptr.hpp"
#include "../Transformations/Basis.h"


using namespace glm;
class Camera {
public:
    Basis camera_basis;
    vec4 position = vec4(0, 0, 0, 0);
    Camera();
    Camera(vec4 position);
    void Rotate(vec4 axis);
    void Translate(vec4 translation);
};


#endif //TEST_CAMERA_H
