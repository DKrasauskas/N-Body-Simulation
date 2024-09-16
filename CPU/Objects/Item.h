//
// Created by dominykas on 10-11-23.
//

#ifndef TEST_ITEM_H
#define TEST_ITEM_H

#include "../../GLFW/glm/glm.hpp"
#include "../../GLFW/glm/gtc/matrix_transform.hpp"
#include "../../GLFW/glm/gtc/type_ptr.hpp"
#include "../../Glad/glad.h"
#include "../../GLFW/GLFW/glfw3.h"
#include <iostream>
#include <memory>

/*
 * Each Item (sphere cube etc) possesses two important features : centroid location (vec3 position) and axis (which can be modified to rotate the object)
 */

template <typename T>
struct  Array{
    T* array;
    int size;
};

struct Point{
    glm::vec3 position;
    glm::vec3 velocity;
};

class Item {
public:
    //properties
    glm::vec3 axis;
    glm::vec3 position = glm::vec3(0 ,0 ,0);
    glm::vec3 velocity = glm::vec3(0, 0, 0);
    glm::vec3 acceleration = glm::vec3(0, 0 ,0);
    float mass = 1;//default is set to one

    // render attributes
    unsigned int VAO, VBO, EBO;
    Array<std::shared_ptr<float>> vertices;
    Array<std::shared_ptr<unsigned int>> indices;
    Item(){};
    Item(std::shared_ptr<float> vertices, int size, std::shared_ptr<unsigned int> indices, int isize);
    Item(std::shared_ptr<float>* vertices, int size, std::shared_ptr<unsigned int> indices, int isize,  unsigned int** VAO,unsigned int** VBO, unsigned int** EBO, int index);
    void Scale(float constant);
   // ~Item();
private:
    void GenVAO();
    void GenVAO(unsigned int** VAOs,unsigned int** VBO, unsigned int** EBO, int index);
};



#endif //TEST_ITEM_H
