#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include "ToolBox/Model.h"
#include "ToolBox/Shader.h"
#include "ToolBox/Inputs.h"
#include "ToolBox/Camera.h"

#include "UI/TsrtsUI.hpp"
#include "UI/PropertiesPanel.hpp"

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
		void initEngine();
		void runEngine();
		void destroyEngine();
		void createframebuffer(int width, int height);

	private:
		GLFWwindow* m_window;
		unsigned int m_width = 1280, m_height = 1024;
		std::vector<std::string> splitKeys(const std::string& input);
		std::vector<std::string> m_keys;
		std::vector<Model> m_Models;
		unsigned int m_framebuffer, m_colorbuffer, m_renderbuffer;
		float m_preTime = 0;
		float m_deltaTime = 0;
		const char* m_basicVertexShader = "ToolBox/Shaders/model.vert" ;
		const char* m_basicFragmentShader = "ToolBox/Shaders/model.frag";

		std::shared_ptr<KeyboardInputs> m_inputHandler;
		std::shared_ptr<tsrtUI> m_Interface;
		std::shared_ptr<PropertiesPanel> m_propertiesPanel;
		std::shared_ptr<Camera> m_camera;
	};
}