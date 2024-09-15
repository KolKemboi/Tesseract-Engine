#pragma once

//THIS IS THE DOCKING BRANCH OF IMGUI
//I DIDN'T NEED THE DOCKING FEATURES, BUT WHO ARE WE KIDDING, IT LOOKS COOL, SO FUCK IT
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


/*
	using the TsrtUI namespace for my Tesseract's UI
	This is to create a distinction from other UI libs that might be included in future
*/
namespace TsrtUI
{
	class tsrtUI
	{
	public:
		;

		tsrtUI(GLFWwindow* window, const char* version)
		{
			IMGUI_CHECKVERSION();
			ImGui::CreateContext();
			ImGuiIO& io= ImGui::GetIO();

			//some configs for docking windows 
			io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
			io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
			io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

			ImGui::StyleColorsDark();
			ImGui_ImplGlfw_InitForOpenGL(window, true);
			ImGui_ImplOpenGL3_Init(version);
		}

		void createNewFrame()
		{
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();
		}

		void setDockable()
		{
			//some other configs I know nothing About
			//I just Know they make the windows dockable
			ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImGui::SetNextWindowPos(viewport->Pos);
			ImGui::SetNextWindowSize(viewport->Size);
			ImGui::SetNextWindowViewport(viewport->ID);

			ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar |
				ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
				ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus |
				ImGuiWindowFlags_NoNavFocus;

			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);

			ImGui::Begin("DockSpace", nullptr, window_flags);
			ImGui::PopStyleVar(2);

			ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_PassthruCentralNode);

			ImGui::End();

		}

		void render()
		{
			//renders the frames
			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
			ImGuiIO& io = ImGui::GetIO(); // FIRST BUG I RAN T
 			
			//some other other configs I know nothing About
			if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
			{
				GLFWwindow* current_context_backup = glfwGetCurrentContext();
				ImGui::UpdatePlatformWindows();
				ImGui::RenderPlatformWindowsDefault();
				glfwMakeContextCurrent(current_context_backup);
			}

		}
		
		void DestroyInstance()
		{
			//Destroys the instance of IMGUI created
			ImGui_ImplGlfw_Shutdown();
			ImGui_ImplOpenGL3_Shutdown();
			ImGui::DestroyContext();
		}

	private:
		
	};
}