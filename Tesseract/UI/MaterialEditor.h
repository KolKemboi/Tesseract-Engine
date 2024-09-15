#pragma once

#include "TsrtUI.h"

namespace TsrtUI
{
	class MaterialEditor
	{
	public:
		void RenderMaterialEditor()
		{
			this->renderMaterialEditor();
		}
	private:
		void renderMaterialEditor()
		{
			ImGui::Begin("Material Editor");
			ImGui::End();
		}
	};
}