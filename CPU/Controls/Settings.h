//
// Created by dominykas on 12-11-23.
//

#ifndef TEST_SETTINGS_H
#define TEST_SETTINGS_H

struct Keyboard{
     int fly_forward     = GLFW_KEY_W;
     int fly_back        = GLFW_KEY_S;
     int fly_left        = GLFW_KEY_A;
     int fly_right       = GLFW_KEY_D;
     int fly_up          = GLFW_KEY_LEFT_SHIFT;
     int fly_down        = GLFW_KEY_LEFT_CONTROL;
     int toggle_rotate   = GLFW_KEY_R;
     int rotate_z_pos    = GLFW_KEY_Q;
     int rotate_z_neg    = GLFW_KEY_E;

     float translation_speed = 1.0f;
     float rotation_Speed = 0.1f;
};
#endif //TEST_SETTINGS_H
