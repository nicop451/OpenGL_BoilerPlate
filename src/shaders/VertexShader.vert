#version 460 core

layout (location = 0) in vec3 aPos;

void main()
{
    // Pass the vertex position to the fragment shader without any transformation
    gl_Position = vec4(aPos, 1.0);
}
