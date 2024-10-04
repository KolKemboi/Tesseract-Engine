#include "Camera.h"

/*
spotlight default => 0.5
pointlight default => 0.3
sun default => 1


CAMERA POS => Z DIST => 12
			=> X DIST =>8
			=> Y DIST => 7
*/

Tsrt::Camera::Camera()
{
	this->m_pos = glm::vec3(13.0f, 13.0f, 13.0f);
	this->m_right = glm::vec3(1.0f, 0.0f, 0.0f);
	this->m_up = glm::vec3(0.0f, 1.0f, 0.0f);
	this->m_camFOV = 45.0f;
	this->m_nearPlane = 0.1f;
	this->m_farPlane = 1000.0f;
	this->m_pitch = 0.0f;
	this->m_yaw = 90.0f;

	this->updateCamVecs();

}

void Tsrt::Camera::setPerspective(Shader& shader,unsigned int windowWidth, unsigned int windowHeight)
{
	//get the mat4, -> camFOV, window width, window height, far plane, and near plane
	this->m_projection = glm::perspective(this->m_camFOV, (GLfloat)windowWidth / windowHeight, this->m_nearPlane, this->m_farPlane);
	shader.setMat4("projection", this->m_projection);
}

void Tsrt::Camera::setView(Shader& shader)
{
	//get the view, -> pos, pos + up, front
	this->m_view = glm::lookAt(this->m_pos, this->m_pos + this->m_front, this->m_up);
	shader.setMat4("view", this->m_view);
}

void Tsrt::Camera::lookAround(std::string const& keyPressed)
{
}

void Tsrt::Camera::moveAround(std::string const& keyPressed)
{
}

void Tsrt::Camera::updateCamVecs()
{
}
