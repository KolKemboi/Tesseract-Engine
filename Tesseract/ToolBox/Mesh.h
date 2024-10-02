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

	class Mesh
	{
	public:
		unsigned int m_vao;
		std::vector<Vertex> m_vertices;
		std::vector<unsigned int> m_indices;

		Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
		void MeshDestroyer();
		void DrawMesh();

	private:
		unsigned int m_vbo, m_ebo;
		void setupMesh();
	};

}