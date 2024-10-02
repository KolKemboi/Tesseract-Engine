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

	this->m_tesseract = std::make_shared<Model>("TsrtAssets/Tesseract.obj");
}

void Tsrt::Engine::runEngine()
{
	while (!glfwWindowShouldClose(this->m_window))
	{
		glClearColor(0.2, 0.1, 0.3, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		this->m_tesseract->DrawModel();

		glfwSwapBuffers(this->m_window);
		glfwPollEvents();

	}
}

void Tsrt::Engine::destroyEngine()
{
	glfwDestroyWindow(this->m_window);
	this->m_window= 0;
	glfwTerminate();
}
