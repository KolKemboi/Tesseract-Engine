#include "Mesh.h"

TsrtMesh::Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices)
{
	this->_vertices = vertices;
	this->_indices = indices;
	this->setupMesh();
}

void TsrtMesh::Mesh::Draw(TsrtShader::Shader& shader)
{
	this->drawMesh(shader);
}

void TsrtMesh::Mesh::setupMesh()
{
	
	glGenVertexArrays(1, &this->_vao);
	glBindVertexArray(TsrtMesh::Mesh::_vao);

	glGenBuffers(1, &this->_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, this->_vbo);
	glBufferData(GL_ARRAY_BUFFER, this->_vertices.size() * sizeof(Vertex), &this->_vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &this->_ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->_indices.size() * sizeof(unsigned int), &this->_indices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Position));
	
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
	
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));

	glBindVertexArray(0);


}

void TsrtMesh::Mesh::drawMesh(TsrtShader::Shader& shader)
{
	glBindVertexArray(this->_vao);
	glDrawElements(GL_TRIANGLES, this->_indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
