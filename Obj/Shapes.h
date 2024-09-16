//
// Created by dominykas on 9-10-23.
//

#ifndef TEST_SHAPES_H
#define TEST_SHAPES_H


class Shapes {
public:
    Shapes(float* vertices, int size);
    Shapes();
    float* vertices;
    int size;
    void GenerateCube();
};


#endif //TEST_SHAPES_H
