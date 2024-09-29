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

	this->window = glfwCreateWindow(this->width, this->height, "Tesseract", nullptr, nullptr);
	if (this->window == NULL)
	{
		std::cerr << "FAILED::WINDOW_CREATION::TERMINATE" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(this->window);
	gladLoadGL();
	glViewport(0, 0, static_cast<unsigned int>(this->width), static_cast<unsigned int>(this->height));
	glEnable(GL_DEPTH_TEST);

	int widthImg, heightImg, nrChannels;
	unsigned char* imageIcon = stbi_load("Logo.png", &widthImg, &heightImg, &nrChannels, 0);
	if (imageIcon)
	{
		GLFWimage icons[1];
		icons[0].pixels = imageIcon;
		icons[0].width = widthImg;
		icons[0].height = heightImg;

		glfwSetWindowIcon(this->window, 1, icons);

	}
	else
	{
		std::cerr << "FAILED::ICON_LOADING" << std::endl;
	}
}

void Tsrt::Engine::runEngine()
{
	while (!glfwWindowShouldClose(this->window))
	{
		glClearColor(0.2, 0.1, 0.3, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		glfwSwapBuffers(this->window);
		glfwPollEvents();

	}
}

void Tsrt::Engine::destroyEngine()
{
	glfwDestroyWindow(this->window);
	this->window = 0;
	glfwTerminate();
}
