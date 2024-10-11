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
	glfwSwapInterval(1);

	this->m_Interface = std::make_shared<tsrtUI>(this->m_window);
	this->m_propertiesPanel = std::make_shared<PropertiesPanel>();

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
		
		this->m_keys = splitKeys(key);

		for (const auto& m_key : m_keys) std::cout << m_key << std::endl;

		float crntTime = glfwGetTime();
		this->m_deltaTime = crntTime - this->m_preTime;
		this->m_preTime = crntTime;

		if (key.find(" ESCAPE ") != std::string::npos) glfwSetWindowShouldClose(this->m_window, true);

		this->m_camera->moveAround(key, this->m_deltaTime);

		std::cout << key << std::endl;
		this->m_Interface->createNewFrame();
		this->m_Interface->setDockable();


		ImGui::Begin("Scene");
		ImVec2 viewportSize = ImGui::GetContentRegionAvail();
		float viewportWidth = viewportSize.x;
		float viewportHeight = viewportSize.y;


		if (viewportWidth != this->m_width || viewportHeight != this->m_height)
		{
			this->m_width = static_cast<int>(viewportWidth);
			this->m_height= static_cast<int>(viewportHeight);
			this->createframebuffer(this->m_width, this->m_height);

		}
		glBindFramebuffer(GL_FRAMEBUFFER, this->m_framebuffer);

		glViewport(0, 0, static_cast<GLsizei>(viewportWidth), static_cast<GLsizei>(viewportHeight));
		glClearColor(0.2, 0.1, 0.3, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		this->m_defaultScene->DrawModel(*this->m_camera, static_cast<GLsizei>(viewportWidth), static_cast<GLsizei>(viewportHeight));

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		ImVec2 uv0(0.0f, 1.0f);
		ImVec2 uv1(1.0f, 0.0f);

		ImGui::Image((void*)(intptr_t)this->m_colorbuffer, viewportSize, uv0, uv1);
		ImGui::End();



		this->m_propertiesPanel->RenderPropertiesPanel();

		this->m_Interface->render();

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
	this->m_Interface->DestroyInstance();
	glfwDestroyWindow(this->m_window);
	this->m_window= 0;
	glfwTerminate();
}

void Tsrt::Engine::createframebuffer(int width, int height)
{
	glGenFramebuffers(1, &this->m_framebuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, this->m_framebuffer);

	glGenTextures(1, &this->m_colorbuffer);
	glBindTexture(GL_TEXTURE_2D, this->m_colorbuffer);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
		0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, this->m_colorbuffer, 0);

	glGenRenderbuffers(1, &this->m_renderbuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, this->m_renderbuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, this->m_renderbuffer);

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;

	glBindFramebuffer(GL_FRAMEBUFFER, 0);

}

std::vector<std::string> Tsrt::Engine::splitKeys(const std::string& input)
{
	std::vector<std::string> res;
	std::istringstream stream(input);
	std::string word;

	while (stream >> word) res.push_back(word);


	return res;
}
