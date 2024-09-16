//
// Created by dominykas on 9-10-23.
//
#pragma once
#include <iostream>
#include "Shapes.h"

Shapes::Shapes(float *vertices, int size) {
    this->vertices = vertices;
    this->size = size;
}
Shapes::Shapes() {}
void Shapes::GenerateCube() {
    vertices = (float*)malloc(sizeof(float)*24);
    int gcount = 0;
    for(float i = 0; i < 3; i+=2.0f){
        for(float j = 0; j < 3; j+=2.0f){
            for(float k = 0; k < 3; k+=2.0f){
                vertices[gcount] = i-1.0f;
                vertices[gcount+1] = j-1.0f;
                vertices[gcount+2] = k-1.0f;
                gcount += 3;
            }
        }
    }
}