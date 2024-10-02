#include "Mesh.h"

Tsrt::Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, const char* vertexPath, const char* fragmentPath)
{
	this->m_vertices = vertices;
	this->m_indices = indices;
	this->m_modelVertexFile = vertexPath;
	this->m_modelFragmentFile = fragmentPath;
	this->setupMesh();
}

void Tsrt::Mesh::MeshDestroyer()
{
	glDeleteVertexArrays(1, &m_vao);
	glDeleteBuffers(1, &m_vbo);
	glDeleteBuffers(1, &m_ebo);

	this->m_ebo = 0;
	this->m_vbo = 0;
	this->m_vao = 0;
}

void Tsrt::Mesh::DrawMesh()
{
	this->modelShader->useShader();
	glBindVertexArray(this->m_vao);
	glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(this->m_indices.size()), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Tsrt::Mesh::setupMesh()
{
	glGenVertexArrays(1, &this->m_vao);
	glBindVertexArray(this->m_vao);

	glGenBuffers(1, &this->m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo);
	glBufferData(GL_ARRAY_BUFFER, this->m_vertices.size() * sizeof(Vertex), &this->m_vertices[0], GL_STATIC_DRAW);
	
	glGenBuffers(1, &this->m_ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->m_indices.size() * sizeof(unsigned int), &this->m_indices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Position));
	
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));

	glBindVertexArray(0);

	try 
	{
		this->modelShader = std::make_shared<Shader>(this->m_modelVertexFile, this->m_modelFragmentFile);
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << "RUNTIME ERROR::" << e.what() << std::endl;
	}
}
