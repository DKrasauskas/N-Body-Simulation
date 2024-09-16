//
// Created by dominykas on 9-10-23.
//
#pragma once
#include <iostream>
#include "../../Glad/glad.h"
#include "../../GLFW/GLFW/glfw3.h"
#include "../../GLFW/glm/glm.hpp"
#include "../../GLFW/glm/gtc/matrix_transform.hpp"
#include "../../GLFW/glm/gtc/type_ptr.hpp"
#include "Render.h"
#include "../Controls/Camera.h"
#include "../Controls/Settings.h"
#include "../Physics.h"

//#include "../Rotations/Quaternions.h"

Render::Render(unsigned int& program) {
   this->program = program;
    GL_POLYGON_MODE;
}

float rot = 0.01f;

using namespace glm;


void PollControls2(Camera& cam, glm::vec4& position, GLFWwindow* window){
    float sensitivity = 1;
    double xpos, ypos;
    float angle;
    glfwGetCursorPos(window, &xpos, &ypos);
    angle = -(ypos-500)/1940*sensitivity;
    vec4 axisT = cam.camera_basis.basis*vec4(1, 0, 0, 0);
    axisT.w = angle;
    cam.Rotate(vec4(axisT));
   // std::cout << " " << axisT.x <<" " <<  axisT.y << " " << axisT.z << "\n";
    angle = -(xpos-500)/1940*sensitivity;
    cam.Rotate(vec4(0, 1, 0, angle));
    glfwSetCursorPos(window, 500, 500);
}
glm::vec4 pos = glm::vec4(0, 0, -8, 0);

void Render::Send(const char* var_name, mat4 variable){
        int loc = glGetUniformLocation(program, var_name); //It is assumed the programmer will provide the correct address here, so no double checks are performed.
        glUniformMatrix4fv(loc,1, GL_FALSE, value_ptr(variable));
}
void Render::Send(const char* var_name, vec4 variable){
    int loc = glGetUniformLocation(program, var_name); //It is assumed the programmer will provide the correct address here, so no double checks are performed.
    glUniform4fv(loc,1, value_ptr(variable));
}
void Render::Send(const char* var_name, vec3 variable){
    int loc = glGetUniformLocation(program, var_name); //It is assumed the programmer will provide the correct address here, so no double checks are performed.
    glUniform3fv(loc,1, value_ptr(variable));
}
void HandleSettings(GLFWwindow* window,  Camera& camera){
    Keyboard keyboard;
    if(glfwGetKey(window, keyboard.fly_forward) == GLFW_PRESS){
       // std::cout << "press\n";
        camera.Translate(camera.camera_basis.basis[2]*keyboard.translation_speed);
      //  std::cout << "moved towards : " << " "<< camera.camera_basis.basis[2].x << "AB "<< camera.camera_basis.basis[2].y<< "AB "<< camera.camera_basis.basis[2].z << "\n";
    }
    if(glfwGetKey(window, keyboard.fly_back) == GLFW_PRESS){
        std::cout << "press\n";
        camera.Translate(camera.camera_basis.basis[2]*(-keyboard.translation_speed));
    }
    if(glfwGetKey(window, keyboard.fly_right) == GLFW_PRESS){
        std::cout << "press\n";
        camera.Translate(camera.camera_basis.basis[0]*-keyboard.translation_speed);
    }
    if(glfwGetKey(window, keyboard.fly_left) == GLFW_PRESS){
        std::cout << "press\n";
        camera.Translate(camera.camera_basis.basis[0]*(keyboard.translation_speed));
    }
    if(glfwGetKey(window, keyboard.rotate_z_neg) == GLFW_PRESS){
        std::cout << "presRs\n";
        vec4 vectorius = vec4(camera.camera_basis.basis[2]);
        vectorius.w = 0.01;
        camera.Rotate(vectorius);
    }
    if(glfwGetKey(window, keyboard.rotate_z_pos) == GLFW_PRESS){
        vec4 vectorius = vec4(camera.camera_basis.basis[2]);
        vectorius.w = -0.01;
        camera.Rotate(vectorius);
    }
    if(glfwGetKey(window, keyboard.fly_up) == GLFW_PRESS){
        camera.Translate(camera.camera_basis.basis[1]*(-keyboard.translation_speed));
    }
    if(glfwGetKey(window, keyboard.fly_down) == GLFW_PRESS){
        camera.Translate(camera.camera_basis.basis[1]*(keyboard.translation_speed));
    }
}

float timestamp = 0.08f;
void HandlePhysics(Item* items, int size, int index, Item& item){
    vec3 displacement = vec3(0, 0, 0);
    vec3 acceleration;
    for(int i = index+1; i < size; i++){

          acceleration= Physica::g(item.mass, item.position-items[i].position);
          items[i].acceleration -= acceleration;
          item.acceleration += acceleration;
           /*if(dot(item.position - items[i].position, item.position - items[i].position) < 4){
                vec3 change_in_v = dot(normalize(item.velocity- items[i].velocity), normalize(item.position - items[i].position))*item.velocity;
                item.velocity =  (item.velocity +items[i].velocity);
                items[i].velocity =  item.velocity;
                item.position -= change_in_v*(float)0.1;

                return;
            }*/
           // items[i].velocity += displacement*timestamp;
           // items[i].position += item.velocity*timestamp;

    }
    item.velocity +=item.acceleration * timestamp;
    item.position += item.velocity*timestamp;
    item.acceleration = displacement;
   // item.velocity += displacement*timestamp;
   // item.position += item.velocity*timestamp;
}

vec3 self_axis = vec4(1, 0, 0, 0);
void Render::Run(Camera& camera, Item* items, int size, glm::mat4& view, glm::mat4& projection, glm::mat4& model, GLFWwindow* window, GLFWcursor* cursor){

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program);
    Send("projection", projection);
    Send("view", view);
    Send("offset", camera.position);
    Send("look", pos);
    mat4 inverse = mat4(1);
    inverse[0] = camera.camera_basis.basis[0];
    inverse[1] = camera.camera_basis.basis[1];
    inverse[2] = camera.camera_basis.basis[2];
    inverse[3] = vec4(0, 0, 0, 1);
    inverse = transpose(inverse);
    Send("view_direction", inverse);
    Send("camera_global", vec3(camera.camera_basis.basis[3].x, camera.camera_basis.basis[3].y, camera.camera_basis.basis[3].z));
    self_axis = Transform::Rotates(vec3(self_axis.x, self_axis.y, self_axis.z), vec4(normalize(vec3(1, 1, 1)), 0.0015));
    for(int i = 0; i < size; i ++){
        glBindVertexArray(items[i].VAO);
     //   HandlePhysics(items, size, i, items[i]);
        Send("position", items[i].position);
        Send("scale", vec3(1, 0, 0));
        Send("self_axis", vec4(self_axis, rot));
        Send("rotaxis", glm::vec4 (normalize(items[i].axis),1));
        glm::mat4 translation = glm::mat4(1.0);
        translation = glm::translate(translation, items[i].position);
        Send("model", translation);
        rot += 0.01f;

        //glDrawElements(GL_POINTS, 10000, GL_UNSIGNED_INT, 0);
    }
    glDrawArrays(GL_POINTS, 0, 1);

   // glDrawElements(GL_POINTS, 100, GL_UNSIGNED_INT, 0);

   // PrintBasis();
   //std::cout<< (cam.camera_basis.basis*vec4(0, 0, 1, 0)).x << "AB "<< (cam.camera_basis.basis*vec4(0, 0, 1, 0)).y<< "AB "<< (cam.camera_basis.basis*vec4(0, 0, 1, 0)).z << "\n";
    HandleSettings(window, camera);
    PollControls2(camera, pos, window);
}
void Render::Runs(unsigned int& VAO, Camera& camera, glm::mat4& view, glm::mat4& projection, glm::mat4& model, GLFWwindow* window, GLFWcursor* cursor){

    //std::cout << "WGS"<<GL_MAX_COMPUTE_WORK_GROUP_SIZE << "\n";
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(Cprogram);
    glDispatchCompute( 40000/16, 1, 1 );
    glMemoryBarrier( GL_SHADER_STORAGE_BARRIER_BIT );
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glUseProgram(program);
    glBindVertexArray(VAO);
    Send("projection", projection);
    Send("view", view);
    Send("offset", camera.position);
    Send("look", pos);
    mat4 inverse = mat4(1);
    inverse[0] = camera.camera_basis.basis[0];
    inverse[1] = camera.camera_basis.basis[1];
    inverse[2] = camera.camera_basis.basis[2];
    inverse[3] = vec4(0, 0, 0, 1);
    inverse = transpose(inverse);
    Send("view_direction", inverse);
    Send("camera_global", vec3(camera.camera_basis.basis[3].x, camera.camera_basis.basis[3].y, camera.camera_basis.basis[3].z));
    self_axis = Transform::Rotates(vec3(self_axis.x, self_axis.y, self_axis.z), vec4(normalize(vec3(1, 1, 1)), 0.0015));
    glm::mat4 translation = glm::mat4(1.0);
    translation = glm::translate(translation, vec3(0, 0, 0));
    Send("model", translation);
   // glDrawArrays(GL_POINTS, 0, 9);
    glDrawElements(GL_POINTS, 40000, GL_UNSIGNED_INT, 0);
    //glBindVertexArray(0);
    // PrintBasis();
    //std::cout<< (cam.camera_basis.basis*vec4(0, 0, 1, 0)).x << "AB "<< (cam.camera_basis.basis*vec4(0, 0, 1, 0)).y<< "AB "<< (cam.camera_basis.basis*vec4(0, 0, 1, 0)).z << "\n";
    HandleSettings(window, camera);
    PollControls2(camera, pos, window);
}
void Render::RunControls(Camera& camera, glm::mat4& view, glm::mat4& projection, glm::mat4& model, GLFWwindow* window, GLFWcursor* cursor){

   // glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    Send("projection", projection);
    Send("view", view);
    Send("offset", camera.position);
    Send("look", pos);
    mat4 inverse = mat4(1);
    inverse[0] = camera.camera_basis.basis[0];
    inverse[1] = camera.camera_basis.basis[1];
    inverse[2] = camera.camera_basis.basis[2];
    inverse[3] = vec4(0, 0, 0, 1);
    inverse = transpose(inverse);
    Send("view_direction", inverse);
    Send("camera_global", vec3(camera.camera_basis.basis[3].x, camera.camera_basis.basis[3].y, camera.camera_basis.basis[3].z));
    self_axis = Transform::Rotates(vec3(self_axis.x, self_axis.y, self_axis.z), vec4(normalize(vec3(1, 1, 1)), 0.0015));
    // PrintBasis();
    //std::cout<< (cam.camera_basis.basis*vec4(0, 0, 1, 0)).x << "AB "<< (cam.camera_basis.basis*vec4(0, 0, 1, 0)).y<< "AB "<< (cam.camera_basis.basis*vec4(0, 0, 1, 0)).z << "\n";
    HandleSettings(window, camera);
    PollControls2(camera, pos, window);
}