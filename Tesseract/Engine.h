#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <stb/stb_image.h>
#include <memory>
#include <iostream>


//INCLUDES THE TESSERACT UI LIBRARY
#include "UI/TsrtUI.h"
#include "UI/PropertiesUI.h"
#include "UI/Viewport.h"
#include "UI/SceneOutliner.h"
#include "UI/MaterialEditor.h"

//MODEL LOADING -> USES THE MESH NAMESPACE AS WE ARE LOADING A MESH 
#include "Model/Model.h"


//CAMERA CLASS
#include "Camera/Camera.h"

//INPUTS CLASS
#include "Inputs/Inputs.h"

namespace TsrtEngine
{
	class tsrtEngine
	{
	public:
		tsrtEngine()
		{
			this->CreateEngine();//creates the engine
		}
		void RunEngine()
		{
			this->runEngine();
		}

		void DestroyEngine()
		{
			this->destroyEngine();
		}
		

	private:
		//UNIQUE PTRS TO THE UI
		std::unique_ptr<TsrtUI::tsrtUI> UI;
		std::unique_ptr<TsrtUI::PropertiesPanel> propertiesPanel;
		std::unique_ptr<TsrtUI::SceneOutliner> sceneOutliner;
		std::unique_ptr<TsrtUI::Viewport> viewport;
		std::unique_ptr<TsrtUI::MaterialEditor> materialEditor;
		std::unique_ptr<TsrtInputs::Inputs> inputs;
		
		GLFWwindow* window;
		
		const unsigned int width = 800, height = 800;

		void CreateEngine()
		{
			//INITS OPENGL AND SETS WINDOW HINTS
			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			//CREATES WINDOW AND SETS THE CURRENT CONTEXT, VIEWPORT AND ENABLES DEPTH TESTION
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

			//SETS THE WINDOW ICON AND SOME ERROR CHECKING
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

			
			//CREATES THE UI
			this->UI = std::make_unique<TsrtUI::tsrtUI>(this->window, "#version 330");
			this->propertiesPanel = std::make_unique<TsrtUI::PropertiesPanel>();
			this->viewport = std::make_unique<TsrtUI::Viewport>();
			this->sceneOutliner = std::make_unique<TsrtUI::SceneOutliner>();
			this->materialEditor = std::make_unique<TsrtUI::MaterialEditor>();

		}
		void runEngine()
		{
			while (!(glfwWindowShouldClose(this->window)))
			{
				//LOOK FOR KEY PRESSES
				this->inputs = std::make_unique<TsrtInputs::Inputs>(this->window);

				glClearColor(0.2f, 0.1f, 0.3f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

				//UI SETUP
				this->UI->createNewFrame();
				this->UI->setDockable();
				
				//UI ELEMENTS
				this->viewport->RendeViewport();
				this->propertiesPanel->RenderPropertiesPanel();
				this->sceneOutliner->RendeSceneOutliner();
				this->materialEditor->RenderMaterialEditor();

				//UI RENDERING
				this->UI->render();
				glfwSwapBuffers(this->window);
				glfwPollEvents();
			}

		}

		void destroyEngine()
		{
			this->UI->DestroyInstance();
			glfwDestroyWindow(this->window);
			glfwTerminate();
		}


	};

}