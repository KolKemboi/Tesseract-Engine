#version 330 core

layout (location = 0) in vec3 Position;  // Vertex position
layout (location = 1) in vec3 Normal;    // Vertex normal
layout (location = 2) in vec2 TexCoords; // Vertex texture coordinates

uniform mat4 model;      // Model matrix
uniform mat4 view;       // View matrix
uniform mat4 projection; // Projection matrix

out vec3 VertexNormal;   // Pass the normal to the fragment shader
out vec2 TextureCoords;  // Pass the texture coordinates to the fragment shader

void main()
{
    gl_Position = vec4(Position, 1.0);
    
    VertexNormal = Normal; // Pass the normal to the fragment shader
    TextureCoords = TexCoords; // Pass the texture coordinates to the fragment shader
}
