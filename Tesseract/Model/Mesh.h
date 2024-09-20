#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


namespace TsrtMesh
{
	struct Vertex
	{
		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec2 TexCoords;
		glm::vec3 Tangents;
		glm::vec3 Bitangents;
	};

	struct Texture
	{
		
	};

	class Mesh
	{
	public:
		Mesh()
		{

		}

	private:

	};
}