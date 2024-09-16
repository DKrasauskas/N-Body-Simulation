//
// Created by dominykas on 14-11-23.
//

#ifndef TEST_PHYSICS_H
#define TEST_PHYSICS_H

/*
 * constants
 */
#pragma once

#define G 9.67*10e-2
/*
 *
 */
namespace Physica{
    glm::vec3 g(float M, glm::vec3 distance){
        return -(float)(G*M/(glm::dot(distance, distance)+0.1))*glm::normalize(distance);
    }
    glm::vec3 dR(float m, float M, glm::vec3 distance, float timestep){
        return g(M, distance)*timestep;
    }
}


#endif //TEST_PHYSICS_H
