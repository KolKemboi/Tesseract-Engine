#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>



namespace TsrtShader
{
	class Shader
	{
	public:

		Shader(const char* meshId)
		{

			if (std::strcmp(meshId, "object") == 0)
			{
				std::string objectVert = "objectShader.vert";
				std::string objectFrag = "objectShader.frag";
			}
			else if (std::strcmp(meshId, "light") == 0)
			{
				std::string lightVert = "lightShader.vert";
				std::string lightFrag = "lightShader.frag";
			}
			//load the vert and frag files

			//create the shaders


		}

		unsigned int getShader()
		{
			return this->shaderProgram;
		}

	private:
		unsigned int shaderProgram, vertex, fragment;

		void checkShaderError(unsigned int shader, const char* type)
		{

		}
	};
}