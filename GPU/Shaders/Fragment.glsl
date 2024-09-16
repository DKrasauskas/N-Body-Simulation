
#version 430 core

out vec4 FragColor;
in vec4 aColor;

//uniform vec4 vertexColor;

vec4 color_map(float data) {
    //data -= 0.01f;
    data = abs(data);
    if (data < 0.166f) {
        return vec4(0.0, 0.0, data * 6, 1.0f);
    }
    if (data < 0.333f) {
        return vec4(0.0, (data - 0.1666f) * 6, 1.0f,  1.0);
    }
    if (data < 0.5f) {
        return vec4(0.0,  1.0, 1.0 - (data - 0.33f) * 6, 1.0);
    }
    if (data < 0.666f) {
        return vec4((data - 0.5f) * 6, 1.0, 0.0f, 1.0);
    }
    if (data < 0.8333f) {
        return vec4(1.0, 1.0 - (data - 0.66f) * 6, 0.0, 1.0);
    }
    if (data < 1.0f) {
        return vec4(1.0 - (data - 0.833f) * 6, 0.0f, 0.0, 1.0);
    }
    return vec4(1, 1, 1, 1);
}
void main(){
    FragColor = color_map(0.001f * aColor.x * aColor.x + 0.001f * aColor.y * aColor.y + 0.1f);
}