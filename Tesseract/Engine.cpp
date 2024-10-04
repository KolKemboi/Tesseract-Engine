#include "Engine.h"


Tsrt::Engine::Engine()
{
	this->initEngine();
}

void Tsrt::Engine::EngineDestroyer()
{
	this->destroyEngine();
}

void Tsrt::Engine::EngineRun()
{
	this->runEngine();
}

void Tsrt::Engine::initEngine()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	this->m_window= glfwCreateWindow(this->m_width, this->m_height, "Tesseract", nullptr, nullptr);
	if (this->m_window== NULL)
	{
		std::cerr << "FAILED::WINDOW_CREATION::TERMINATE" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(this->m_window);
	gladLoadGL();
	glViewport(0, 0, static_cast<unsigned int>(this->m_width), static_cast<unsigned int>(this->m_height));
	glEnable(GL_DEPTH_TEST);

	int widthImg, heightImg, nrChannels;
	unsigned char* imageIcon = stbi_load("Logo.png", &widthImg, &heightImg, &nrChannels, 0);
	if (imageIcon)
	{
		GLFWimage icons[1];
		icons[0].pixels = imageIcon;
		icons[0].width = widthImg;
		icons[0].height = heightImg;

		glfwSetWindowIcon(this->m_window, 1, icons);

	}
	else
	{
		std::cerr << "FAILED::ICON_LOADING" << std::endl;
	}

	this->m_tesseract = std::make_shared<Model>("TsrtAssets/Tesseract.obj",
		"ToolBox/Shaders/model.vert", "ToolBox/Shaders/model.frag");

	this->m_defaultScene = std::make_shared<Model>("TsrtAssets/default scene.obj",
		"ToolBox/Shaders/model.vert", "ToolBox/Shaders/model.frag");

		
	this->m_inputHandler = std::make_shared<KeyboardInputs>(this->m_window);
	this->m_inputHandler->callBackFunction();
	this->m_camera = std::make_shared<Camera>();
}

void Tsrt::Engine::runEngine()
{
	while (!glfwWindowShouldClose(this->m_window))
	{
		std::string key = this->m_inputHandler->keyPressed();
		std::transform(key.begin(), key.end(), key.begin(), ::toupper);
		
		if (std::strcmp(key.c_str(), "ESCAPE") == 0) glfwSetWindowShouldClose(this->m_window, true);

		glClearColor(0.2, 0.1, 0.3, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//this->m_tesseract->DrawModel(*this->m_camera);
		this->m_defaultScene->DrawModel(*this->m_camera);

		glfwSwapBuffers(this->m_window);
		glfwPollEvents();

	}
}

/*
spotlight default => 0.5
pointlight default => 0.3
sun default => 1


CAMERA POS => Z DIST => 12
			=> X DIST =>8
			=> Y DIST => 7
*/

void Tsrt::Engine::destroyEngine()
{
	this->m_inputHandler->KeyboardInputsDestroyer();
	glfwDestroyWindow(this->m_window);
	this->m_window= 0;
	glfwTerminate();
}
