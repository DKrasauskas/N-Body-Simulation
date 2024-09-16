//
// Created by dominykas on 4-11-23.
//

#include "Shapes.h"




namespace Object{
    Sphere sphere1;
}
void Shapes::GenerateCube(int rez, float **src, int &index, unsigned int **EBO, int &eb) {
    float* source= (float*)malloc(sizeof(float)*(rez*rez*4*3*6));
    unsigned int* ebo= (unsigned int*)malloc(sizeof(unsigned int)*(rez*rez*3*2*6));
    float* sourcearray = (float*)malloc(sizeof(float)*(rez+4));
    for(int i = 0; i <= rez; i++) {
        sourcearray[i] = -0.5f+(float) i / rez;
    }
    for(int i = 1; i <= rez; i++){
        for(int j = 1; j <= rez; j ++){
            source[index] = sourcearray[i-1];
            source[index+1] = sourcearray[j-1];
            source[index+2] = 0.5f;
            index += 3;
            source[index] = sourcearray[i];
            source[index+1] = sourcearray[j-1];
            source[index+2] = 0.5f;
            index += 3;
            source[index] = sourcearray[i];
            source[index+1] = sourcearray[j];
            source[index+2] = 0.5f;
            index += 3;
            source[index] = sourcearray[i-1];
            source[index+1] = sourcearray[j];
            source[index+2] = 0.5f;
            index += 3;
            ebo[eb] = index/3-4;
            ebo[eb+1] = index/3-3;
            ebo[eb+2] = index/3-2;
            ebo[eb+3] = index/3-4;
            ebo[eb+4] = index/3-1;
            ebo[eb+5] = index/3-2;
            eb += 6;
            source[index] = sourcearray[i-1];
            source[index+1] = sourcearray[j-1];
            source[index+2] = -0.5f;
            index += 3;
            source[index] = sourcearray[i];
            source[index+1] = sourcearray[j-1];
            source[index+2] = -0.5f;
            index += 3;
            source[index] = sourcearray[i];
            source[index+1] = sourcearray[j];
            source[index+2] = -0.5f;
            index += 3;
            source[index] = sourcearray[i-1];
            source[index+1] = sourcearray[j];
            source[index+2] = -0.5f;
            index += 3;
            ebo[eb] = index/3-4;
            ebo[eb+1] = index/3-3;
            ebo[eb+2] = index/3-2;
            ebo[eb+3] = index/3-4;
            ebo[eb+4] = index/3-1;
            ebo[eb+5] = index/3-2;
            eb += 6;
            source[index] = sourcearray[i-1];
            source[index+1] = -0.5f;
            source[index+2] = sourcearray[j-1];
            index += 3;
            source[index] = sourcearray[i];
            source[index+1] = -0.5f;
            source[index+2] = sourcearray[j-1];
            index += 3;
            source[index] = sourcearray[i];
            source[index+1] = -0.5f;
            source[index+2] = sourcearray[j];
            index += 3;
            source[index] = sourcearray[i-1];
            source[index+1] = -0.5f;
            source[index+2] = sourcearray[j];
            index += 3;
            ebo[eb] = index/3-4;
            ebo[eb+1] = index/3-3;
            ebo[eb+2] = index/3-2;
            ebo[eb+3] = index/3-4;
            ebo[eb+4] = index/3-1;
            ebo[eb+5] = index/3-2;
            eb += 6;
            source[index] = sourcearray[i-1];
            source[index+1] = 0.5f;
            source[index+2] = sourcearray[j-1];
            index += 3;
            source[index] = sourcearray[i];
            source[index+1] = 0.5f;
            source[index+2] = sourcearray[j-1];
            index += 3;
            source[index] = sourcearray[i];
            source[index+1] = 0.5f;
            source[index+2] = sourcearray[j];
            index += 3;
            source[index] = sourcearray[i-1];
            source[index+1] = 0.5f;
            source[index+2] = sourcearray[j];
            index += 3;
            ebo[eb] = index/3-4;
            ebo[eb+1] = index/3-3;
            ebo[eb+2] = index/3-2;
            ebo[eb+3] = index/3-4;
            ebo[eb+4] = index/3-1;
            ebo[eb+5] = index/3-2;
            eb += 6;
            source[index] = -0.5f;
            source[index+1] = sourcearray[i-1];
            source[index+2] = sourcearray[j-1];
            index += 3;
            source[index] = -0.5f;
            source[index+1] = sourcearray[i];
            source[index+2] = sourcearray[j-1];
            index += 3;
            source[index] = -0.5f;
            source[index+1] = sourcearray[i];
            source[index+2] = sourcearray[j];
            index += 3;
            source[index] = -0.5f;
            source[index+1] = sourcearray[i-1];
            source[index+2] = sourcearray[j];
            index += 3;
            ebo[eb] = index/3-4;
            ebo[eb+1] = index/3-3;
            ebo[eb+2] = index/3-2;
            ebo[eb+3] = index/3-4;
            ebo[eb+4] = index/3-1;
            ebo[eb+5] = index/3-2;
            eb += 6;
            source[index] = 0.5f;
            source[index+1] = sourcearray[i-1];
            source[index+2] = sourcearray[j-1];
            index += 3;
            source[index] = 0.5f;
            source[index+1] = sourcearray[i];
            source[index+2] = sourcearray[j-1];
            index += 3;
            source[index] = 0.5f;
            source[index+1] = sourcearray[i];
            source[index+2] = sourcearray[j];
            index += 3;
            source[index] = 0.5f;
            source[index+1] = sourcearray[i-1];
            source[index+2] = sourcearray[j];
            index += 3;
            ebo[eb] = index/3-4;
            ebo[eb+1] = index/3-3;
            ebo[eb+2] = index/3-2;
            ebo[eb+3] = index/3-4;
            ebo[eb+4] = index/3-1;
            ebo[eb+5] = index/3-2;
            eb += 6;
        }
    }
    free(sourcearray);
    *src = source;
    *EBO = ebo;
}
//int resolution, bool convert_to_sphere?
void Shapes::GenerateCube(int rez, bool convert_to_sphere) {
    Object::sphere1.vertices= (float*)malloc(sizeof(float)*(rez*rez*4*3*6));
    Object::sphere1.EBO= (unsigned int*)malloc(sizeof(unsigned int)*(rez*rez*3*2*6));
    Object::sphere1.v_size = 0;
    Object::sphere1.ebo_size =0;
    float* sourcearray = (float*)malloc(sizeof(float)*(rez+4));

    for(int i = 0; i <= rez; i++) {
        sourcearray[i] = -0.5f+(float) i / rez;
    }
    for(int i = 1; i <= rez; i++){
        for(int j = 1; j <= rez; j ++){
            Object::sphere1.vertices[Object::sphere1.v_size] = sourcearray[i-1];
            Object::sphere1.vertices[Object::sphere1.v_size+1] = sourcearray[j-1];
            Object::sphere1.vertices[Object::sphere1.v_size+2] = 0.5f;
            Object::sphere1.v_size += 3;
            Object::sphere1.vertices[Object::sphere1.v_size] = sourcearray[i];
            Object::sphere1.vertices[Object::sphere1.v_size+1] = sourcearray[j-1];
            Object::sphere1.vertices[Object::sphere1.v_size+2] = 0.5f;
            Object::sphere1.v_size += 3;
            Object::sphere1.vertices[Object::sphere1.v_size] = sourcearray[i];
            Object::sphere1.vertices[Object::sphere1.v_size+1] = sourcearray[j];
            Object::sphere1.vertices[Object::sphere1.v_size+2] = 0.5f;
            Object::sphere1.v_size += 3;
            Object::sphere1.vertices[Object::sphere1.v_size] = sourcearray[i-1];
            Object::sphere1.vertices[Object::sphere1.v_size+1] = sourcearray[j];
            Object::sphere1.vertices[Object::sphere1.v_size+2] = 0.5f;
            Object::sphere1.v_size += 3;
            Object::sphere1.EBO[Object::sphere1.ebo_size] = Object::sphere1.v_size/3-4;
            Object::sphere1.EBO[Object::sphere1.ebo_size+1] = Object::sphere1.v_size/3-3;
            Object::sphere1.EBO[Object::sphere1.ebo_size+2] = Object::sphere1.v_size/3-2;
            Object::sphere1.EBO[Object::sphere1.ebo_size+3] = Object::sphere1.v_size/3-4;
            Object::sphere1.EBO[Object::sphere1.ebo_size+4] = Object::sphere1.v_size/3-1;
            Object::sphere1.EBO[Object::sphere1.ebo_size+5] = Object::sphere1.v_size/3-2;
            Object::sphere1.ebo_size+= 6;
            Object::sphere1.vertices[Object::sphere1.v_size] = sourcearray[i-1];
            Object::sphere1.vertices[Object::sphere1.v_size+1] = sourcearray[j-1];
            Object::sphere1.vertices[Object::sphere1.v_size+2] = -0.5f;
            Object::sphere1.v_size += 3;
            Object::sphere1.vertices[Object::sphere1.v_size] = sourcearray[i];
            Object::sphere1.vertices[Object::sphere1.v_size+1] = sourcearray[j-1];
            Object::sphere1.vertices[Object::sphere1.v_size+2] = -0.5f;
            Object::sphere1.v_size += 3;
            Object::sphere1.vertices[Object::sphere1.v_size] = sourcearray[i];
            Object::sphere1.vertices[Object::sphere1.v_size+1] = sourcearray[j];
            Object::sphere1.vertices[Object::sphere1.v_size+2] = -0.5f;
            Object::sphere1.v_size += 3;
            Object::sphere1.vertices[Object::sphere1.v_size] = sourcearray[i-1];
            Object::sphere1.vertices[Object::sphere1.v_size+1] = sourcearray[j];
            Object::sphere1.vertices[Object::sphere1.v_size+2] = -0.5f;
            Object::sphere1.v_size += 3;
            Object::sphere1.EBO[Object::sphere1.ebo_size] = Object::sphere1.v_size/3-4;
            Object::sphere1.EBO[Object::sphere1.ebo_size+1] = Object::sphere1.v_size/3-3;
            Object::sphere1.EBO[Object::sphere1.ebo_size+2] = Object::sphere1.v_size/3-2;
            Object::sphere1.EBO[Object::sphere1.ebo_size+3] = Object::sphere1.v_size/3-4;
            Object::sphere1.EBO[Object::sphere1.ebo_size+4] = Object::sphere1.v_size/3-1;
            Object::sphere1.EBO[Object::sphere1.ebo_size+5] = Object::sphere1.v_size/3-2;
            Object::sphere1.ebo_size+= 6;
            Object::sphere1.vertices[Object::sphere1.v_size] = sourcearray[i-1];
            Object::sphere1.vertices[Object::sphere1.v_size+1] = -0.5f;
            Object::sphere1.vertices[Object::sphere1.v_size+2] = sourcearray[j-1];
            Object::sphere1.v_size += 3;
            Object::sphere1.vertices[Object::sphere1.v_size] = sourcearray[i];
            Object::sphere1.vertices[Object::sphere1.v_size+1] = -0.5f;
            Object::sphere1.vertices[Object::sphere1.v_size+2] = sourcearray[j-1];
            Object::sphere1.v_size += 3;
            Object::sphere1.vertices[Object::sphere1.v_size] = sourcearray[i];
            Object::sphere1.vertices[Object::sphere1.v_size+1] = -0.5f;
            Object::sphere1.vertices[Object::sphere1.v_size+2] = sourcearray[j];
            Object::sphere1.v_size += 3;
            Object::sphere1.vertices[Object::sphere1.v_size] = sourcearray[i-1];
            Object::sphere1.vertices[Object::sphere1.v_size+1] = -0.5f;
            Object::sphere1.vertices[Object::sphere1.v_size+2] = sourcearray[j];
            Object::sphere1.v_size += 3;
            Object::sphere1.EBO[Object::sphere1.ebo_size] = Object::sphere1.v_size/3-4;
            Object::sphere1.EBO[Object::sphere1.ebo_size+1] = Object::sphere1.v_size/3-3;
            Object::sphere1.EBO[Object::sphere1.ebo_size+2] = Object::sphere1.v_size/3-2;
            Object::sphere1.EBO[Object::sphere1.ebo_size+3] = Object::sphere1.v_size/3-4;
            Object::sphere1.EBO[Object::sphere1.ebo_size+4] = Object::sphere1.v_size/3-1;
            Object::sphere1.EBO[Object::sphere1.ebo_size+5] = Object::sphere1.v_size/3-2;
            Object::sphere1.ebo_size+= 6;
            Object::sphere1.vertices[Object::sphere1.v_size] = sourcearray[i-1];
            Object::sphere1.vertices[Object::sphere1.v_size+1] = 0.5f;
            Object::sphere1.vertices[Object::sphere1.v_size+2] = sourcearray[j-1];
            Object::sphere1.v_size += 3;
            Object::sphere1.vertices[Object::sphere1.v_size] = sourcearray[i];
            Object::sphere1.vertices[Object::sphere1.v_size+1] = 0.5f;
            Object::sphere1.vertices[Object::sphere1.v_size+2] = sourcearray[j-1];
            Object::sphere1.v_size += 3;
            Object::sphere1.vertices[Object::sphere1.v_size] = sourcearray[i];
            Object::sphere1.vertices[Object::sphere1.v_size+1] = 0.5f;
            Object::sphere1.vertices[Object::sphere1.v_size+2] = sourcearray[j];
            Object::sphere1.v_size += 3;
            Object::sphere1.vertices[Object::sphere1.v_size] = sourcearray[i-1];
            Object::sphere1.vertices[Object::sphere1.v_size+1] = 0.5f;
            Object::sphere1.vertices[Object::sphere1.v_size+2] = sourcearray[j];
            Object::sphere1.v_size += 3;
            Object::sphere1.EBO[Object::sphere1.ebo_size] = Object::sphere1.v_size/3-4;
            Object::sphere1.EBO[Object::sphere1.ebo_size+1] = Object::sphere1.v_size/3-3;
            Object::sphere1.EBO[Object::sphere1.ebo_size+2] = Object::sphere1.v_size/3-2;
            Object::sphere1.EBO[Object::sphere1.ebo_size+3] = Object::sphere1.v_size/3-4;
            Object::sphere1.EBO[Object::sphere1.ebo_size+4] = Object::sphere1.v_size/3-1;
            Object::sphere1.EBO[Object::sphere1.ebo_size+5] = Object::sphere1.v_size/3-2;
            Object::sphere1.ebo_size+= 6;
            Object::sphere1.vertices[Object::sphere1.v_size] = -0.5f;
            Object::sphere1.vertices[Object::sphere1.v_size+1] = sourcearray[i-1];
            Object::sphere1.vertices[Object::sphere1.v_size+2] = sourcearray[j-1];
            Object::sphere1.v_size += 3;
            Object::sphere1.vertices[Object::sphere1.v_size] = -0.5f;
            Object::sphere1.vertices[Object::sphere1.v_size+1] = sourcearray[i];
            Object::sphere1.vertices[Object::sphere1.v_size+2] = sourcearray[j-1];
            Object::sphere1.v_size += 3;
            Object::sphere1.vertices[Object::sphere1.v_size] = -0.5f;
            Object::sphere1.vertices[Object::sphere1.v_size+1] = sourcearray[i];
            Object::sphere1.vertices[Object::sphere1.v_size+2] = sourcearray[j];
            Object::sphere1.v_size += 3;
            Object::sphere1.vertices[Object::sphere1.v_size] = -0.5f;
            Object::sphere1.vertices[Object::sphere1.v_size+1] = sourcearray[i-1];
            Object::sphere1.vertices[Object::sphere1.v_size+2] = sourcearray[j];
            Object::sphere1.v_size += 3;
            Object::sphere1.EBO[Object::sphere1.ebo_size] = Object::sphere1.v_size/3-4;
            Object::sphere1.EBO[Object::sphere1.ebo_size+1] = Object::sphere1.v_size/3-3;
            Object::sphere1.EBO[Object::sphere1.ebo_size+2] = Object::sphere1.v_size/3-2;
            Object::sphere1.EBO[Object::sphere1.ebo_size+3] = Object::sphere1.v_size/3-4;
            Object::sphere1.EBO[Object::sphere1.ebo_size+4] = Object::sphere1.v_size/3-1;
            Object::sphere1.EBO[Object::sphere1.ebo_size+5] = Object::sphere1.v_size/3-2;
            Object::sphere1.ebo_size+= 6;
            Object::sphere1.vertices[Object::sphere1.v_size] = 0.5f;
            Object::sphere1.vertices[Object::sphere1.v_size+1] = sourcearray[i-1];
            Object::sphere1.vertices[Object::sphere1.v_size+2] = sourcearray[j-1];
            Object::sphere1.v_size += 3;
            Object::sphere1.vertices[Object::sphere1.v_size] = 0.5f;
            Object::sphere1.vertices[Object::sphere1.v_size+1] = sourcearray[i];
            Object::sphere1.vertices[Object::sphere1.v_size+2] = sourcearray[j-1];
            Object::sphere1.v_size += 3;
            Object::sphere1.vertices[Object::sphere1.v_size] = 0.5f;
            Object::sphere1.vertices[Object::sphere1.v_size+1] = sourcearray[i];
            Object::sphere1.vertices[Object::sphere1.v_size+2] = sourcearray[j];
            Object::sphere1.v_size += 3;
            Object::sphere1.vertices[Object::sphere1.v_size] = 0.5f;
            Object::sphere1.vertices[Object::sphere1.v_size+1] = sourcearray[i-1];
            Object::sphere1.vertices[Object::sphere1.v_size+2] = sourcearray[j];
            Object::sphere1.v_size += 3;
            Object::sphere1.EBO[Object::sphere1.ebo_size] = Object::sphere1.v_size/3-4;
            Object::sphere1.EBO[Object::sphere1.ebo_size+1] = Object::sphere1.v_size/3-3;
            Object::sphere1.EBO[Object::sphere1.ebo_size+2] = Object::sphere1.v_size/3-2;
            Object::sphere1.EBO[Object::sphere1.ebo_size+3] = Object::sphere1.v_size/3-4;
            Object::sphere1.EBO[Object::sphere1.ebo_size+4] = Object::sphere1.v_size/3-1;
            Object::sphere1.EBO[Object::sphere1.ebo_size+5] = Object::sphere1.v_size/3-2;
            Object::sphere1.ebo_size+= 6;
        }
    }
    if(convert_to_sphere)ToSphere(Object::sphere1.vertices, Object::sphere1.v_size);
    free(sourcearray);
}
void Shapes::ToSphere(float *arr, int size) {
    for(int i = 0; i < size; i +=3){
        float norm = 1/sqrt(arr[i]*arr[i]+arr[i+1]*arr[i+1]+arr[i+2]*arr[i+2]);
        arr[i] *= norm;
        arr[i+1] *= norm;
        arr[i+2] *= norm;
    }
}
void Shapes::Offset(float x, float y, float z){
    for(int i = 0; i < Object::sphere1.v_size; i +=3){
        Object::sphere1.vertices[i] += x;
        Object::sphere1.vertices[i] += y;
        Object::sphere1.vertices[i] += z;
    }
}
void Shapes::GenerateSphere(int rez, float **src, int &index, unsigned int **EBO, int &eb) {
    GenerateCube(rez, src, index,EBO, eb);
    ToSphere(*src, index);
}
