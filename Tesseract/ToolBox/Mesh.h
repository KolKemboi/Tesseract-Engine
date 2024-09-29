#pragma once

#include "../tspch.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


namespace Tsrt
{
	struct Vertex
	{
		glm::vec3 Position;
		glm::vec3 Normal;
	};

	class TsrtMesh
	{
	public:
		unsigned int _vao;
		std::vector<Vertex> _vertices;
		std::vector<unsigned int> _indices;

		TsrtMesh(std::vector<Vertex> _vertices, std::vector<unsigned int> _indices);
		void MeshDestroyer();
		void DrawMesh();

	private:
		unsigned int _vbo, _ebo;

		void setupMesh();
	};

}