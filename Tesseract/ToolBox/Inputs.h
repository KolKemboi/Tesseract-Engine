#pragma once

#include "../tspch.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Tsrt
{
	class KeyboardInputs
	{
	public:
		KeyboardInputs(GLFWwindow* window);
		void KeyboardInputsDestroyer();
		void callBackFunction();
		std::string keyPressed();

	private:
		bool m_keys[1024];
		GLFWwindow* m_window;

		std::vector <std::string> m_keysPressed;

		static KeyboardInputs* m_instance;

		static void keyCallBack(GLFWwindow* window, int key, int scanCode, int action, int mode);
	};

}