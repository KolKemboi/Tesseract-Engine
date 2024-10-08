#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include "ToolBox/Model.h"
#include "ToolBox/Shader.h"
#include "ToolBox/Inputs.h"
#include "ToolBox/Camera.h"

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
		std::vector<std::string> splitKeys(const std::string& input);
		std::vector<std::string> m_keys;

		float m_preTime = 0;
		float m_deltaTime = 0;
		std::shared_ptr<KeyboardInputs> m_inputHandler;
		std::shared_ptr<Model> m_tesseract;
		std::shared_ptr<Model> m_cube;
		std::shared_ptr<Model> m_defaultScene;
		std::shared_ptr<Model> m_plane;
		std::shared_ptr<Model> m_pointLight;
		std::shared_ptr<Model> m_sunLight;
		std::shared_ptr<Model> m_spotLight;
		std::shared_ptr<Camera> m_camera;
	};
}