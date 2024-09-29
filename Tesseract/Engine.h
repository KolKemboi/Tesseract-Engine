#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include "tspch.h"

namespace Tsrt
{
	class Engine
	{
	public:
		Engine();
		void EngineDestroyer();
		void EngineRun();

	private:
		GLFWwindow* window;
		unsigned int width = 800, height = 800;
		void initEngine();
		void runEngine();
		void destroyEngine();
	};
}