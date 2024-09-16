//
// Created by dominykas on 28-9-23.
//
#pragma once
#include "Shader.h"


Shader::Shader(const char *inputVertex, const char *inputFragment) {
    unsigned int vertex, fragment;
    const char* source = Shader::Parse(inputVertex);
    const char* source2 = Shader::Parse(inputFragment);
    BuildShaders(vertex, source, GL_VERTEX_SHADER);
    BuildShaders(fragment, source2, GL_FRAGMENT_SHADER);
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    Link(ID);
    std::cout << "rim\n";
}
Shader::Shader(const char *inputVertex, const char *inputFragment, const char* inputCompute) {
    unsigned int vertex, fragment, compute;
    const char* source = Shader::Parse(inputVertex);
    const char* source2 = Shader::Parse(inputFragment);
    const char* source3 = Shader::Parse(inputCompute);
    BuildShaders(vertex, source, GL_VERTEX_SHADER);
    BuildShaders(fragment, source2, GL_FRAGMENT_SHADER);
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    Link(ID);
    BuildShaders(compute, source3, GL_COMPUTE_SHADER);
    PID = glCreateProgram();
    glAttachShader(PID, compute);
    Link(PID);
}
//converts input string to char array
char* Shader::Parse(string input){
    cout << input <<"\n";
    ifstream in(input);
    if(!in.is_open()) {
        cout << "ERROR:FILE NOT FOUND\n";
        int k;
        cin >> k;
    }
    std::stringstream buffer;
    buffer << in.rdbuf();
    string s = buffer.str();
    char* out = (char*)malloc(sizeof(char)*(s.length()+1));
    for(int i = 0; i < s.length(); i ++){
        out[i] = s[i];
    }
    out[s.length()] = '\0';
    return out;
}

void Shader::BuildShaders(unsigned int &shader, const char* source, uint32_t shader_type){
    shader = glCreateShader(shader_type);
    glShaderSource(shader, 1,  &source, NULL);
    int success;
    char err[512];
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(shader, 512, NULL, err);
        std::cout << "shader Compilation failed" << shader_type<< err << "\n";
        int k;
        cin >> k;
    }
}
void Shader::Link(unsigned int&program){
    glLinkProgram(program);
    int success;
    char err[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success){

        glGetProgramInfoLog(program, 512, NULL, err);
        std::cout << "Linking failed" << err << "\n";
        throw;
    }
}

