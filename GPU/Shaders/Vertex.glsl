#version 430 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location = 1) in vec3 aPos2;

out vec4 aColor; // to be sent via pipeline to color shader

uniform mat4  model, projection;

uniform vec3 offset = vec3(0, 0, 0);
uniform vec3 position = vec3(0, 0, -4);


uniform vec4 self_axis= vec4(0, 0, 1, 0);

uniform mat4 view_direction = mat4(1);
uniform vec3 camera_global;

uniform vec3 scale;
uniform struct Item{
    vec4 axis;
    vec4 position;
};
struct Quaternion{
    float rpart;
    vec3 vpart;
};

//The rotation members may not be needed on the gpu
Quaternion multiply(Quaternion rhs, Quaternion lhs){
    Quaternion a;
    a.rpart = lhs.rpart*rhs.rpart - dot(lhs.vpart, rhs.vpart);
    a.vpart = lhs.rpart * rhs.vpart + rhs.rpart*lhs.vpart + cross(lhs.vpart, rhs.vpart);
    return a;
}

vec3 Rotate(vec4 axis, vec3 initial){
    Quaternion lhs, rhs, vector;
    lhs.rpart = cos(axis.w);
    rhs.rpart = cos(axis.w);
    lhs.vpart = sin(axis.w)*vec3(axis.x, axis.y, axis.z);
    rhs.vpart = sin(axis.w)*(-1.0f)*vec3(axis.x, axis.y, axis.z);
    vector.rpart = 0;
    vector.vpart = initial;
    Quaternion naujas;
    naujas = multiply(lhs, vector);
    naujas = multiply(naujas, rhs);
    return naujas.vpart;
}
vec3 Rotate(vec4 axis, vec3 initial, vec3 offset){
    initial = initial + offset;
    Quaternion lhs, rhs, vector;
    lhs.rpart = cos(axis.w);
    rhs.rpart = cos(axis.w);
    lhs.vpart = sin(axis.w)*vec3(axis.x, axis.y, axis.z);
    rhs.vpart = sin(axis.w)*(-1.0f)*vec3(axis.x, axis.y, axis.z);
    vector.rpart = 0;
    vector.vpart = initial;
    Quaternion naujas;
    naujas = multiply(lhs, vector);
    naujas = multiply(naujas, rhs);
    naujas.vpart = naujas.vpart+offset;
    return naujas.vpart;
}

struct ST{
    vec4 pos;
};
layout(std140, binding = 3) buffer name
{
    ST data_SSBO[];
};
layout(std140, binding = 4) buffer pos
{
    vec4 acc[];
};
void main()
{
    mat4 views = view_direction;
    vec3 data = vec3(0, 0,0 );
   // data *= scale.x;
    //data.z -= scale.x;
    //this is deprecated. It is unwise to perform 100x100x4 rotations instead of just 4
    //data = Rotate(self_axis, data);
    data += vec3(data_SSBO[gl_VertexID].pos.x, data_SSBO[gl_VertexID].pos.y, 0.0f)+camera_global;
    gl_Position = views*model*(vec4(data, 1.0f));
    gl_Position = projection*gl_Position;
   // gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    aColor = vec4(acc[gl_VertexID].x, acc[gl_VertexID].y, 0, 0);
}