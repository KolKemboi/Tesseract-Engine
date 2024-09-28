#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "../Shaders/Shader.h"

namespace TsrtMesh
{
	struct Vertex
	{
		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec2 TexCoords;
	};

	struct Texture
	{
		
	};

	class Mesh
	{
	public:
		unsigned int _vao;
		std::vector<Vertex> _vertices;
		std::vector<unsigned int> _indices;

		Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
		void Draw(TsrtShader::Shader& shader);

	private:
		unsigned int _vbo, _ebo;

		void setupMesh();
		void drawMesh(TsrtShader::Shader& shader);

	};
}