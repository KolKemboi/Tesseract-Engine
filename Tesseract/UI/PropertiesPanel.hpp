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
			ImGui::End();
		}
	};

}