#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <unordered_map>


//re-write this class properly
namespace TsrtInputs
{
	class Inputs
	{
	public:
		Inputs(GLFWwindow* window)
		{
			this->window = window;
			this->keyboardCallback(this->keyboard);
		}
		std::unordered_map<const char*, int> getKey()
		{
			return keyboard;
		}


	private:
		bool keys[1024];
		GLFWwindow* window;
		std::unordered_map<const char*, int> keyboard;
		std::unordered_map<const char*, int> mouse;

		void keyboardCallback(std::unordered_map<const char*, int> keyboard)
		{
			keyboard["W"] = glfwGetKey(this->window, GLFW_KEY_W);
			keyboard["A"] = glfwGetKey(this->window, GLFW_KEY_A);
			keyboard["S"] = glfwGetKey(this->window, GLFW_KEY_S);
			keyboard["D"] = glfwGetKey(this->window, GLFW_KEY_D);
		}
		void mouseCallback(std::unordered_map<const char*, int> mouse)
		{

		}
	};
}