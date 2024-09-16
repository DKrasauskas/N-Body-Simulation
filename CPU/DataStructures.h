//
// Created by dominykas on 15-11-23.
//

#ifndef TEST_DATASTRUCTURES_H
#define TEST_DATASTRUCTURES_H


#include "../GLFW/glm/glm.hpp"
#include "../GLFW/glm/gtc/matrix_transform.hpp"
#include "../GLFW/glm/gtc/type_ptr.hpp"

class DataStructures {

};

class Node;

struct Child{
    Node* NW;
    Node* NE;
    Node* SW;
    Node* SE;
};

class Node{
    bool end = false;
    Child nodes;
    glm::vec4 origin, body;
    Node();
    Node(glm::vec4 origin);
    void Insert(glm::vec4 body);
    void Expand();
};
class QuadTree{
  Node primary;
};

#endif //TEST_DATASTRUCTURES_H
