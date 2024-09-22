#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <unordered_map>

#include "../Shaders/Shader.h"

namespace TsrtCamera
{
	enum Cam_Movement
	{
		FORWARD,
		BACKWARD,
		RIGHT,
		LEFT,
		UP,
		DOWN,
	};

	class Camera
	{
	public:
		Camera(glm::vec3 position = glm::vec3(0.0f, 1.0f, 3.0f), glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f), 
			glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3 right = glm::vec3(1.0f, 0.0f, 0.0f)):
			pos(position), front(front), up(up), right(right)
		{

		}

		void lookAround(std::unordered_map<const char*, int>key)
		{
			//using the scroll button, onPress

		}
		void moveAround(std::unordered_map<const char*, int>key)
		{

		}

		void setview()
		{
			//set the View Loc 

		}
		void setProjection()
		{
			//set the projection Loc 
		}


	private:
		glm::vec3 pos, front, up, right;
		glm::mat4 view, projection;
		float sensitivity, FOV, speed;

	};
}