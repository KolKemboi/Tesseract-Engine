#pragma once

#include "TsrtUI.h"

namespace TsrtUI
{
	class SceneOutliner
	{
	public:
		void RendeSceneOutliner()
		{
			this->renderSceneOutliner();
		}
	private:
		void renderSceneOutliner()
		{
			ImGui::Begin("Scene Outliner");
			ImGui::End();
		}
	};
}