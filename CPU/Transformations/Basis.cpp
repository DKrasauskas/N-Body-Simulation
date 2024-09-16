//
// Created by dominykas on 12-11-23.
//

#pragma once
#include "Basis.h"
#include "Rotations/Quaternions.h"


Basis::Basis() = default;
Basis::Basis(vec3 x, vec3 y, vec3 z) {
    basis[0] = vec4(x, 0);
    basis[1] = vec4(y, 0);
    basis[2] = vec4(z, 0);
}

void Transform::Rotate(Basis& origin, vec4& axis){
        origin.basis[0]  = vec4(Rotations::Rotate(axis, origin.basis[0]), 0);
        origin.basis[1]  = vec4(Rotations::Rotate(axis, origin.basis[1]), 0);
        origin.basis[2]  = vec4(Rotations::Rotate(axis, origin.basis[2]), 0);
}
vec3 Transform::Rotates(vec3 origin, vec4 axis){
    return vec3(Rotations::Rotate(axis, origin));
}