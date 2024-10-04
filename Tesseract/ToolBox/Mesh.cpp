#include "Mesh.h"

Tsrt::Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, 
	const char* vertexFile, const char* fragmentFile)
{
	this->m_vertexFile = vertexFile;
	this->m_fragmentFile = fragmentFile;
	this->m_vertices = vertices;
	this->m_indices = indices;
	this->m_modelMatrix = glm::mat4(1.0f);
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

void Tsrt::Mesh::DrawMesh(Camera& camera)
{
	camera.setPerspective(*this->m_meshShader, 800, 800);
	camera.setView(*this->m_meshShader);
	this->setModelMatrix(glm::vec3(0.0f, 0.0f, 0.0f),glm::vec3(0.0f, 0.0f, 0.0f),glm::vec3(1.0f),
		*this->m_meshShader);

	this->m_meshShader->useShader();
	glBindVertexArray(this->m_vao);
	glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(this->m_indices.size()), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Tsrt::Mesh::setModelMatrix(glm::vec3 modelPos, glm::vec3 modelRot, glm::vec3 modelScale, Shader& shader)
{
	this->m_modelMatrix = glm::mat4(1.0f);  
	this->m_modelMatrix = glm::translate(this->m_modelMatrix, modelPos);
	this->m_modelMatrix = glm::rotate(this->m_modelMatrix, glm::radians(modelRot.x), glm::vec3(1.0f, 0.0f, 0.0f)); 
	this->m_modelMatrix = glm::rotate(this->m_modelMatrix, glm::radians(modelRot.y), glm::vec3(0.0f, 1.0f, 0.0f));
	this->m_modelMatrix = glm::rotate(this->m_modelMatrix, glm::radians(modelRot.z), glm::vec3(0.0f, 0.0f, 1.0f)); 
	this->m_modelMatrix = glm::scale(this->m_modelMatrix, modelScale);
	shader.setMat4("model", this->m_modelMatrix);
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
	
	this->m_meshShader = std::make_shared<Shader>(this->m_vertexFile, this->m_fragmentFile);

	glBindVertexArray(0);
}
