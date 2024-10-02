#pragma once

#include "../tspch.h"
#include "Shader.h"
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

		Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, 
			const char* vertexFile, const char* fragmentFile);

		void MeshDestroyer();
		void DrawMesh();

	private:
		unsigned int m_vbo, m_ebo;

		const char* m_vertexFile;
		const char* m_fragmentFile;

		std::shared_ptr<Shader> m_meshShader;
		void setupMesh();
	};

}