//
// Created by dominykas on 10-11-23.
//

#include "Item.h"
float scale = 3;
Item::Item(std::shared_ptr<float> vertices, int size, std::shared_ptr<unsigned int> indices, int isize) {
    this->vertices = {(&vertices), size};
    std::cout << size << "\n";
    this->indices = {&indices, isize};
    position = glm::vec3 (0,0, 0);
    //Scale(2);
    GenVAO();
}
Item::Item(std::shared_ptr<float>* vertices, int size, std::shared_ptr<unsigned int> indices, int isize,  unsigned int** VAO, unsigned int** VBO, unsigned int** EBO, int index) {
    this->vertices = {&(*vertices), size};
    std::cout << size << "\n";
    this->indices = {&indices, isize};
    position = glm::vec3 (0,0, 0);
    //Scale(2);
    GenVAO(VAO,VBO, EBO, index);
    //std::cout << "ran\n";
}
void Item::Scale(float constant) {
    for(int i = 0; i < vertices.size/4; i ++){
        (*vertices.array).get()[i] *= constant;
    }
}

void Item::GenVAO() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size,  vertices.array->get(), GL_STATIC_DRAW);
    glGenBuffers(1, &(EBO));
    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size, indices.array->get(), GL_STATIC_DRAW);
   // glBindVertexArray(VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 4 * 3, (void*)0);	// Vertex attributes stay the same
    glEnableVertexAttribArray(0);
}
void Item::GenVAO(unsigned int** VAO,unsigned int** VBO, unsigned int** EBO,  int index) {
   // glBindVertexArray((*VAO)[index]);
    glBindBuffer(GL_ARRAY_BUFFER, (*VBO)[index]);
    glBufferData(GL_ARRAY_BUFFER, vertices.size,  vertices.array->get(), GL_STATIC_DRAW);
    glBindVertexArray((*VAO)[index]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, (*EBO)[index]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size, indices.array->get(), GL_STATIC_DRAW);
    // glBindVertexArray(VAO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 4 * 3, (void*)0);	// Vertex attributes stay the same
    glEnableVertexAttribArray(0);

}
