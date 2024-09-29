#version 330 core

out vec4 FragColor;

in vec3 VertexNormal;
in vec2 TextureCoords;

void main()
{
	FragColor = vec4(VertexNormal, 1.0f);
}