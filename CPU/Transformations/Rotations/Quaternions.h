//
// Created by dominykas on 12-11-23.
//

#ifndef TEST_QUATERNIONS_H
#define TEST_QUATERNIONS_H
#include "../../../GLFW/glm/glm.hpp"
#include "../../../GLFW/glm/gtc/matrix_transform.hpp"
#include "../../../GLFW/glm/gtc/type_ptr.hpp"
using namespace glm;

class Quaternion {
public:
    float real_part;
    vec3 vector_part = vec3(0);
    Quaternion();
    explicit Quaternion(vec3 vector);
    explicit Quaternion(vec4 vector);
    Quaternion(float real_part, vec3 vector);
    Quaternion operator *(Quaternion rhs) const;

};
namespace Rotations{
    //Rotates a vector around given axis axis.w degrees (4th component of the axis vector)
    vec3 Rotate(vec4 axis, vec3 vector);
}

#endif //TEST_QUATERNIONS_H
