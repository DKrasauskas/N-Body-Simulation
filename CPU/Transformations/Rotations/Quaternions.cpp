//
// Created by dominykas on 12-11-23.
//

#include "Quaternions.h"

Quaternion::Quaternion(glm::vec3 vector){
    real_part = 0;
    vector_part = vector;
}
Quaternion::Quaternion(float angle, glm::vec3 vector){
    real_part = cos(angle);
    vector_part = sin(angle)*vector;
}
Quaternion::Quaternion(glm::vec4 vector){
    real_part = cos(vector.w);
    vector_part = sin(vector.w)*vec3(vector.x, vector.y, vector.z);
}
Quaternion::Quaternion(){
    real_part = 0;
    vector_part = vec3(0, 0 ,0);
}

Quaternion Quaternion::operator*(Quaternion rhs) const {
    Quaternion output;
    output.real_part = real_part*rhs.real_part - dot(vector_part, rhs.vector_part);
    output.vector_part =  real_part * rhs.vector_part + rhs.real_part*vector_part + cross(vector_part, rhs.vector_part);
    return output;
}

vec3 Rotations::Rotate(glm::vec4 axis, glm::vec3 vector) {
    return ((Quaternion(axis)*Quaternion(vector))*Quaternion(axis.w, vec3(-axis.x, -axis.y, -axis.z))).vector_part;
}