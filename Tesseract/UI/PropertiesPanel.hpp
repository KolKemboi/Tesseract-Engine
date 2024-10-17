#pragma once

#include "TsrtsUI.hpp"


namespace Tsrt
{
	class PropertiesPanel
	{
	public:
		void RenderPropertiesPanel()
		{
			this->renderPropertiesPanel();
		}
	private:
		void renderPropertiesPanel()
		{
			ImGui::Begin("Properties");
			ImGui::Button("Load", ImVec2(80, 20));
			ImGui::Button("Save", ImVec2(80, 20));
			ImGui::End();
		}
	};

}