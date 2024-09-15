#pragma once

#include "TsrtUI.h"

namespace TsrtUI
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