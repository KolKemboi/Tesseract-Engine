#include "Shader.h"

TsrtShader::Shader::Shader(const char* meshId)
{
	if (std::strcmp(meshId, "OBJECT") == 0)
	{
		this->vertexFile = "modelShader.vert";
		this->fragmentFile = "modelShader.frag";
	}
	else if (std::strcmp(meshId, "LIGHT") == 0)
	{
		this->vertexFile = "lightShader.vert";
		this->fragmentFile = "lightShader.frag";
	}


	this->createShaders(vertexFile, fragmentFile);
}

unsigned int TsrtShader::Shader::getShader()
{
	return this->_shaderProgram;
}

void TsrtShader::Shader::setBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(this->_shaderProgram, name.c_str()), (int)value);
}

void TsrtShader::Shader::setInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(this->_shaderProgram, name.c_str()), value);
}

void TsrtShader::Shader::setFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(this->_shaderProgram, name.c_str()), value);
}

void TsrtShader::Shader::setVec2(const std::string& name, const glm::vec2& value) const
{
	glUniform2fv(glGetUniformLocation(this->_shaderProgram, name.c_str()), 1, &value[0]);
}

void TsrtShader::Shader::setVec2(const std::string& name, float x, float y) const
{
	glUniform2f(glGetUniformLocation(this->_shaderProgram, name.c_str()), x, y);
}

void TsrtShader::Shader::setVec3(const std::string& name, const glm::vec3& value) const
{
	glUniform3fv(glGetUniformLocation(this->_shaderProgram, name.c_str()), 1, &value[0]);
}

void TsrtShader::Shader::setVec3(const std::string& name, float x, float y, float z) const
{
	glUniform3f(glGetUniformLocation(this->_shaderProgram, name.c_str()), x, y, z);
}

void TsrtShader::Shader::setVec4(const std::string& name, const glm::vec4& value) const
{
	glUniform4fv(glGetUniformLocation(this->_shaderProgram, name.c_str()), 1, &value[0]);
}

void TsrtShader::Shader::setVec4(const std::string& name, float x, float y, float z, float w) const
{
	glUniform4f(glGetUniformLocation(this->_shaderProgram, name.c_str()), x, y, z, w);
}

void TsrtShader::Shader::setMat2(const std::string& name, const glm::mat2& mat) const
{
	glUniformMatrix2fv(glGetUniformLocation(this->_shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);  
}

void TsrtShader::Shader::setMat3(const std::string& name, const glm::mat3& mat) const
{
	glUniformMatrix3fv(glGetUniformLocation(this->_shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);  
}

void TsrtShader::Shader::setMat4(const std::string& name, const glm::mat4& mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(this->_shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);  
}

void TsrtShader::Shader::DestroyShader()
{
	glDeleteProgram(this->_shaderProgram);
	this->_shaderProgram = 0;
}

void TsrtShader::Shader::checkShaderError(unsigned int shader, const char* type)
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

void TsrtShader::Shader::createShaders(const char* vertexFile, const char* fragmentFile)
{
	std::string vertexCode, fragmentCode; //creating place to store the files
	std::ifstream vShaderFile, fShaderFile; // file reader

	//checks for exceptions in the file
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		//vShaderFile.open(vertexFile);
		fShaderFile.open(fragmentFile);
		std::stringstream vShaderStream, fShaderStream;

		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();

	}
	catch (std::ifstream::failure& e)
	{
		std::cerr << "ERROR::SHADER::FILE_NOT_LOADED:: " << e.what() << std::endl;
	}

	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();



	this->_vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(this->_vertex, 1, &vertexSource, NULL);
	glCompileShader(this->_vertex);
	this->checkShaderError(this->_vertex, "VERTEX");
	
	this->_fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(this->_fragment, 1, &fragmentSource, NULL);
	glCompileShader(this->_fragment);
	this->checkShaderError(this->_fragment, "FRAGMENT");

	this->_shaderProgram = glCreateProgram();
	glAttachShader(this->_shaderProgram, this->_vertex);
	glAttachShader(this->_shaderProgram, this->_fragment);
	glLinkProgram(this->_shaderProgram);
	this->checkShaderError(this->_shaderProgram, "PROGRAM");

	glDeleteShader(this->_vertex);
	glDeleteShader(this->_fragment);
}

std::string TsrtShader::Shader::readShadersFromFile(const char* filename)	
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return contents;
	}
	else
	{
		std::cerr << "ERROR::SHADER UPLOAD FAILED:: " << filename << std::endl;
		return "ERROR::";
	}
}
