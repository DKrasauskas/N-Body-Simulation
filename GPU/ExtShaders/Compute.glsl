#version 430 core
#extension GL_ARB_compute_shader : enable
#extension GL_ARB_shader_storage_buffer_object : enable
layout(local_size_x = 16, local_size_y = 1, local_size_z = 1) in;

struct Position{
   vec4 position;
};

layout(std140, binding = 3) buffer pos
{
    vec4 entity[];
};
layout(std140, binding = 4) buffer pos2
{
    vec4 acc[];
};

//uniform vec4 vertexColor;
float G = 0.01f;
float DT = 0.01f;
vec2 acceleration(vec2 position_vector){
    vec2 position = vec2(position_vector.x, position_vector.y);
    return G/(dot(position, position)+0.01)*normalize(position);
}
void main(){
    uint gid = gl_GlobalInvocationID.x + gl_GlobalInvocationID.y *128;
    vec2 accelerations = vec2(0);
    for(int i = 0; i < 40000; i ++){
        if(gid == i) continue;
        accelerations += acceleration(vec2(entity[gid].x-entity[i].x, entity[gid].y-entity[i].y));
    }
    acc[gid] = vec4(accelerations, 0, 0);
    vec2 da = accelerations*DT;
    entity[gid].z-= da.x;
    entity[gid].w-= da.y;
    entity[gid].x += entity[gid].z*DT;
    entity[gid].y += entity[gid].w*DT;
   // pos.pos += v.pos*DT;
    //current_position[gid].position.x += 0.001f;
    //Positions[ gl_GlobalInvocationID.x/4*3+1] += 0.7f;
}



