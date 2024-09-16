//
// Created by dominykas on 25-10-23.
//

#ifndef TEST_ELEMENTARYSHAPES_H
#define TEST_ELEMENTARYSHAPES_H


class ElementaryShapes {
public:
    ElementaryShapes();

      class Element{
      public:
          int size;
          int step;
          float* indices;
          unsigned int* ebo;
          int ebosize;
      };
      Element cube;
      Element triangle;
};


#endif //TEST_ELEMENTARYSHAPES_H
