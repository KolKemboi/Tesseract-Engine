#include "Camera.h"

Tsrt::Camera::Camera()
{

}

void Tsrt::Camera::setPerspective(unsigned int windowWidth, unsigned int windowHeight)
{
	//get the mat4, -> camFOV, window width, window height, far plane, and near plane
}

void Tsrt::Camera::setView()
{
	//get the view, -> pos, pos + up, front
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
