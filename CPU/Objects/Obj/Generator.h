//
// Created by dominykas on 31-10-23.
//
#include <fstream>
#pragma once
#ifndef TEST_GENERATOR_H
#define TEST_GENERATOR_H

struct Point {
    Point(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    Point() {

    }
    float x, y, z;
    Point operator +(Point rhs) {
        return Point(x + rhs.x, y + rhs.y, z + rhs.z);
    }

    Point operator -(Point rhs) {
        return Point(x - rhs.x, y - rhs.y, z - rhs.z);
    }
    Point operator /(float val) {
        return Point(x /val, y /val, z /val);
    }
    Point operator *(float val) {
        return Point(x *val, y *val, z *val);
    }
};
struct rettype{
    rettype(Point* ptr, int size){
        this-> ptr = ptr;
        this-> size =size;
    }
    Point* ptr;
    int size;
};

namespace List{
    Point* list;
    int size, index;
    void Resize(){
        std::cout<<size << "\n";
        list = (Point*)realloc(list, sizeof(Point)*2*size);
        size *= 2;
    }
}

namespace EBO{
    Point* list;
    int size, index;
    void Resize(){
        std::cout<<size << "\n";
        list = (Point*)realloc(list, sizeof(Point)*2*size);
        size *= 2;
    }
}
typedef struct rettype Struct;
Struct ReShuffle(Point* vertices, int depth, int max_depth){
    if(depth ==max_depth) return {vertices, 3};
    Point newpoints[4][3];
    Point A =((vertices)[1])/2 + ((vertices)[0]) / 2;
    Point B =((vertices)[2])/2 + ((vertices)[0]) / 2;
    Point C =((vertices)[2])/2 + ((vertices)[1]) / 2;
    newpoints[0][0]= vertices[0];
    newpoints[0][1]= A;
    newpoints[0][2] = B;
    newpoints[1][0]= vertices[1];
    newpoints[1][1]= A;
    newpoints[1][2] = C;
    newpoints[2][0]= vertices[2];
    newpoints[2][1]= B;
    newpoints[2][2] = C;
    newpoints[3][0]= A;
    newpoints[3][1]= B;
    newpoints[3][2] = C;
    Point* output = (Point*)malloc(sizeof(Point)*3);
    int size = 0;
    int capacity = 3;
    for(int i = 0; i < 4; i++){
        Struct out = ReShuffle(newpoints[i], depth+1, max_depth);
        for(int j = 0;j < out.size; j++){
            output[size] = out.ptr[j];
            size += 1;
            if(size ==capacity){
                capacity *= 2;
                output = (Point*)realloc(output, sizeof(Point)*capacity);
            }
        }

    }
    return {output, size};
}
void Split(Point **arr,int start, int &size) {
    *arr = (Point*)realloc(*arr, sizeof(Point) * (size + 3));
    if (arr == NULL)std::cout << "errf\n";
    std::cout << start << "\n";
    (*arr)[size] = ((*arr)[start + 1])/2 + ((*arr)[start]) / 2;
    (*arr)[size+1] = ((*arr)[start + 2]) / 2 + ((*arr)[start]) / 2;
    (*arr)[size+2] = ((*arr)[start + 2]) / 2 + ((*arr)[start+1]) / 2;
    size += 3;

}
void toFloatArr(Point* arr, int size, std::ofstream& off) {
    float* out = (float*)malloc(sizeof(float) * size * 3);
    int count = 0;
    for (int i = 0; i < size; i++) {
        out[count] = arr[i].x;
        out[count+1] = arr[i].y;
        out[count+2] = arr[i].z;
        count += 3;
    }
    count = 0;
    // std::cout << "float vertices[]{\n";
    for (int i = 0; i < size; i++) {
        off << out[count] << ",";;
        off << out[count+1] << ",";;
        off << out[count+2] << ",\n";
        count += 3;
    }
    free(out);
}
void GenerateSphere(int iteration_depth)
{
    std::ofstream off("/home/dominykas/CLionProjects/test/Obj/SP.h", std::ofstream::out | std::ofstream::trunc);
    off << ("float sphere[]{\n");
    for(int k = -1; k <=1; k+=2) {
        for (int j = -1; j <= 1; j += 2) {
            for (int i = -1; i <= 1; i += 2) {
                Point *arr = (Point *) malloc(sizeof(Point) * 3);
                arr[0] = Point(j * 0.5f, 0.0f, 0.0f);
                arr[1] = Point(-0.0f, 0.0f, k*0.5f);
                arr[2] = Point(0.0f, i * 0.8660254f, 0.0f);
                int size = 3;
                Struct out = ReShuffle(arr, 0, iteration_depth);
                toFloatArr(out.ptr, out.size, off);
                free(arr);
            }
        }
    }
    std::cout << "done generation part\n";
    off << "\n};";

}
void GenerateSphereCube(int iteration_depth)
{
    std::ofstream off("/home/dominykas/CLionProjects/test/Obj/SP.h", std::ofstream::out | std::ofstream::trunc);
    off << ("float sphere[]{\n");
    for(int k = -1; k <=1; k+=2) {
                Point *arr = (Point *) malloc(sizeof(Point) * 3);
                arr[2] = Point(-0.5f, -0.5f, k*0.5f);
                arr[1] = Point(0.5f, -0.5f, k*0.5f);
                arr[0] = Point( 0.5f, 0.5f, k*0.5f);
                int size = 3;
                Struct out = ReShuffle(arr, 0, iteration_depth);
                toFloatArr(out.ptr, out.size, off);
                free(arr);
                arr = (Point *) malloc(sizeof(Point) * 3);
                arr[2] = Point(-0.5f, -0.5f, k*0.5f);
                arr[0] = Point( -0.5f, 0.5f, k*0.5f);
                arr[1] = Point(0.5f, 0.5f, k*0.5f);

                out = ReShuffle(arr, 0, iteration_depth);
                toFloatArr(out.ptr, out.size, off);
                free(arr);
    }
    for(int k = -1; k <=1; k+=2) {
        Point *arr = (Point *) malloc(sizeof(Point) * 3);
        arr[2] = Point(-0.5f, k*0.5f, -0.5f);
        arr[1] = Point(0.5f, k*0.5f, -0.5f);
        arr[0] = Point( 0.5f, k*0.5f, 0.5f);
        int size = 3;
        Struct out = ReShuffle(arr, 0, iteration_depth);
        toFloatArr(out.ptr, out.size, off);
        free(arr);
        arr = (Point *) malloc(sizeof(Point) * 3);
        arr[2] = Point(-0.5f, k*0.5f, -0.5f);
        arr[0] = Point( -0.5f, k*0.5f, 0.5f);
        arr[1] = Point(0.5f, k*0.5f, 0.5f);

        out = ReShuffle(arr, 0, iteration_depth);
        toFloatArr(out.ptr, out.size, off);
        free(arr);
    }
    for(int k = -1; k <=1; k+=2) {
        Point *arr = (Point *) malloc(sizeof(Point) * 3);
        arr[2] = Point(k*0.5f, -0.5f, -0.5f);
        arr[1] = Point(k*0.5f, 0.5f, -0.5f);
        arr[0] = Point( k*0.5f, 0.5f, 0.5f);
        int size = 3;
        Struct out = ReShuffle(arr, 0, iteration_depth);
        toFloatArr(out.ptr, out.size, off);
        free(arr);
        arr = (Point *) malloc(sizeof(Point) * 3);
        arr[2] = Point(k*0.5f, -0.5f, -0.5f);
        arr[0] = Point( k*0.5f, -0.5f, 0.5f);
        arr[1] = Point(k*0.5f, 0.5f, 0.5f);

        out = ReShuffle(arr, 0, iteration_depth);
        toFloatArr(out.ptr, out.size, off);
        free(arr);
    }



}

void AddCube(Point* vertices, Point* output, int& index, int& size){
    int indices[3] = {index, index+1, index+2};
    for(int i = 0; i < 3; i ++){
        List::list[index] = vertices[i];
        index ++;
        if(index >= size){
            List::Resize();
        }
    }
}

void GenerateScalableCube(Point* coords, Point* aux, float res, Point* v, std::ofstream &off){

    for(int i = 1; i <= res; i++){

        for(int j = 1; j <= res; j++){
                coords[0] = aux[0]+v[0]*i +v[1]*j;
                coords[1] = aux[1]+v[0]*(i-1)+v[1]*j;
                coords[2] = aux[2]+v[0]*(i-1)+v[1]*(j-1);
                AddCube(coords, List::list, List::index, List::size);
        }
    }

}
void GenerateScalableCube(Point* coords, Point* aux, float res, Point* v, std::ofstream &off, int h){

    for(int i = 1; i <= res; i++){
        for(int j = 1; j <= res; j++){
            coords[0] = aux[0]-v[0]*i -v[1]*j;
            coords[1] = aux[1]-v[0]*(i-1)- v[1]*j;
            coords[2] = aux[2]-v[0]*(i-1)-v[1]*(j-1);
            AddCube(coords, List::list, List::index, List::size);
        }
    }

}
void GenTextures(float res){
    List::list = (Point*)malloc(sizeof(Point)*res);
    EBO::list = (Point*)malloc(sizeof(Point)*res);
    List::size = res;
    EBO::size = res;
    EBO::index = 0;
    List::index = 0;
    Point coords1[] = {
            {-0.5f, -0.5f, 0.5f,},
            {-0.5f, -0.5f, 0.5f,},
            {-0.5f, -0.5f, 0.5f,}
    };
    Point coords2[] = {
            {-0.5f, -0.5f, -0.5f,},
            {-0.5f, -0.5f, -0.5f,},
            {-0.5f, -0.5f, -0.5f,}
    };
    Point coords3[] = {
            {0.5f, 0.5f, -0.5f,},
            {0.5f, 0.5f, -0.5f,},
            {0.5f, 0.5f, -0.5f,}
    };
    Point vt[]{
            {1/res, 0.0f, 0.0f},
            {0.0f, 1/res, 0.0f}
    };
    Point vt1[]{
            {1/res, 0.0f, 0.0f},
            {0.0f, 0.0f, -1/res}
    };
    Point vt2[]{
            {0.0f, 1/res, 0.0f},
            {0.0f, 0.0f, -1/res}
    };
    std::ofstream off("/home/dominykas/CLionProjects/test/Obj/SP.h", std::ofstream::out | std::ofstream::trunc);
    off << ("float sphere[]{\n");
    GenerateScalableCube(coords2, coords1,  res, vt, off);
    GenerateScalableCube(coords2, coords1,  res, vt1, off);
    GenerateScalableCube(coords2, coords1,  res, vt2, off);
    GenerateScalableCube(coords2, coords3,  res, vt, off, -1);
    GenerateScalableCube(coords2, coords3,  res, vt1, off, -1);
    GenerateScalableCube(coords2, coords3,  res, vt2, off, -1);
    toFloatArr(List::list, List::size, off);
    std::cout << "done generation part\n";
    off << "\n};";
    //GenerateScalableCube(coords2, res);
}

#endif //TEST_GENERATOR_H
