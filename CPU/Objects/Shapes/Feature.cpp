//
// Created by dominykas on 16-11-23.
//

#include "Feature.h"
Feature::Feature(float* vertices, unsigned int vertex_count, unsigned int* indices, unsigned int i_count){
    vertex_array.array = (float*)malloc(sizeof(float)*vertex_count);
    memcpy(vertex_array.array, vertices, sizeof(float)*vertex_count);
    vertex_array.size = vertex_count;
    indices_array.array = (unsigned int *)malloc(sizeof(unsigned int)*i_count);
    memcpy(indices_array.array, indices, sizeof(unsigned int)*i_count);
    indices_array.size = i_count;
}

