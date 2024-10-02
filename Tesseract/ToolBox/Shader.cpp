#include "Shader.h"



Tsrt::Shader::Shader(const char* vertexFile, const char* fragFile)
{
	std::string vertexCode = this->loadShader(vertexFile);
	const char* vertexSource = vertexCode.c_str();

	std::string fragmentCode = this->loadShader(fragFile);
	const char* fragmentSource = fragmentCode.c_str();

	this->m_vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(this->m_vertexShader, 1, &vertexSource, NULL);
	glCompileShader(this->m_vertexShader);
	this->checkCompileErrors(this->m_vertexShader, "VERTEX");

	this->m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(this->m_fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(this->m_fragmentShader);
	this->checkCompileErrors(this->m_fragmentShader, "FRAGMENT");

	this->m_shaderProgram = glCreateProgram();
	glAttachShader(this->m_shaderProgram, this->m_vertexShader);
	glAttachShader(this->m_shaderProgram, this->m_fragmentShader);
	glLinkProgram(this->m_shaderProgram);
	this->checkCompileErrors(this->m_shaderProgram, "SHADER");

}

void Tsrt::Shader::DestroyShader()
{
	this->destroyShader();
}

unsigned int Tsrt::Shader::getShader()
{
	return this->m_shaderProgram;
}

void Tsrt::Shader::useShader()
{
	glUseProgram(this->m_shaderProgram);
}

void Tsrt::Shader::checkCompileErrors(unsigned int shader, const char* type)
{
	int success;
	char infoLog[1024];

	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cerr << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n---------------------------" << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cerr << "ERROR::SHADER_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n---------------------------" << std::endl;
		}
	}

}

void Tsrt::Shader::destroyShader()
{
	glDeleteShader(this->m_vertexShader);
	glDeleteShader(this->m_fragmentShader);
	glDeleteProgram(this->m_shaderProgram);

	this->m_fragmentShader = 0;
	this->m_vertexShader = 0;
	this->m_shaderProgram = 0;
}

std::string Tsrt::Shader::loadShader(const char* filename)
{
	// Open the file
	std::ifstream in(filename);

	// Check if the file opened successfully
	if (!in) {
		std::cerr << "FILE NOT FOUND  " << std::string(filename) << std::endl;
	}

	// Read the file contents into a string stream
	std::stringstream buffer;
	buffer << in.rdbuf();

	// Check if the shader source is empty
	if (buffer.str().empty()) {
		throw std::runtime_error("SHADER FILE::SHADER SOURCE EMPTY:: " + std::string(filename));
	}

	// Return the shader source code as a string
	return buffer.str();
}


// ------------------------SETTING SHADER UNIFORMS ---------------------------- //
void Tsrt::Shader::setBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(this->m_shaderProgram, name.c_str()), (int)value);
}

void Tsrt::Shader::setInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(this->m_shaderProgram, name.c_str()), value);
}

void Tsrt::Shader::setFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(this->m_shaderProgram, name.c_str()), value);
}

void Tsrt::Shader::setVec2(const std::string& name, const glm::vec2& value) const
{
	glUniform2fv(glGetUniformLocation(this->m_shaderProgram, name.c_str()), 1, &value[0]);
}

void Tsrt::Shader::setVec2(const std::string& name, float x, float y) const
{
	glUniform2f(glGetUniformLocation(this->m_shaderProgram, name.c_str()), x, y);
}

void Tsrt::Shader::setVec3(const std::string& name, const glm::vec3& value) const
{
	glUniform3fv(glGetUniformLocation(this->m_shaderProgram, name.c_str()), 1, &value[0]);
}

void Tsrt::Shader::setVec3(const std::string& name, float x, float y, float z) const
{
	glUniform3f(glGetUniformLocation(this->m_shaderProgram, name.c_str()), x, y, z);
}

void Tsrt::Shader::setVec4(const std::string& name, const glm::vec4& value) const
{
	glUniform4fv(glGetUniformLocation(this->m_shaderProgram, name.c_str()), 1, &value[0]);
}

void Tsrt::Shader::setVec4(const std::string& name, float x, float y, float z, float w) const
{
	glUniform4f(glGetUniformLocation(this->m_shaderProgram, name.c_str()), x, y, z, w);
}

void Tsrt::Shader::setMat2(const std::string& name, const glm::mat2& mat) const
{
	glUniformMatrix2fv(glGetUniformLocation(this->m_shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Tsrt::Shader::setMat3(const std::string& name, const glm::mat3& mat) const
{
	glUniformMatrix3fv(glGetUniformLocation(this->m_shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Tsrt::Shader::setMat4(const std::string& name, const glm::mat4& mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(this->m_shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
