//
// Created by dominykas on 11-11-23.
//


#pragma once
#include "Camera.h"
#include <iostream>

Camera::Camera() {
    // standard basis aligned with world coordinates
    camera_basis = Basis();
    camera_basis.basis[0] = vec4(1, 0, -0, 0);
    camera_basis.basis[1] = vec4(0, 1, 0, 0);
    camera_basis.basis[2] = vec4(0, 0, 1, 0);
    camera_basis.basis[3] = vec4(0, 0, 0, 1);
}
Camera::Camera(vec4 position) {
    // standard basis aligned with world coordinates
    camera_basis = Basis();
    camera_basis.basis[0] = vec4(1, 0, -0, 0);
    camera_basis.basis[1] = vec4(0, 1, 0, 0);
    camera_basis.basis[2] = vec4(0, 0, 1, 0);
    camera_basis.basis[3] = vec4(position.x, position.y, position.z, 1);
}

void Camera::Rotate(glm::vec4 axis) {
    Transform::Rotate(camera_basis, axis);
}
void Camera::Translate(glm::vec4 translation){
    //std::cout << camera_basis.basis[2].x << " " << camera_basis.basis[2].y << " " << camera_basis.basis[2].z << " \n";
    camera_basis.basis[3]  += translation;
    //std::cout<< (camera_basis.basis[0].z) << " A" << (camera_basis.basis[1].z) << " A" << (camera_basis.basis[2]).z << "\n";
    position += translation;
}
