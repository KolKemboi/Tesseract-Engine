#pragma once

#include "../tspch.h"
#include "Shader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/rotate_vector.hpp>


namespace Tsrt
{
	class Camera
	{
	public:
		Camera();
		void setPerspective(Shader& shader, unsigned int windowWidth, unsigned int windowHeight);
		void setView(Shader& shader);
		void lookAround(std::string const& keyPressed);
		void moveAround(std::string const& keyPressed);
		void panAround();// impl this feature
	private:
		glm::vec3 m_front, m_up, m_right, m_pos;
		
		glm::mat4 m_projection, m_view;
		

		float m_sensitivity, m_speed, m_pitch, m_yaw, m_camFOV, m_nearPlane, m_farPlane;

		void updateCamVecs();
	};
}