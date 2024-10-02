#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include "ToolBox/Model.h"
#include "ToolBox/Shader.h"

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
		GLFWwindow* m_window;
		unsigned int m_width = 800, m_height = 800;
		void initEngine();
		void runEngine();
		void destroyEngine();

		std::shared_ptr<Model> m_tesseract;
	};
}