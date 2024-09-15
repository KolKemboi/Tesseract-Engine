#pragma once

#include "TsrtUI.h"

namespace TsrtUI
{
	class Viewport
	{
	public:
		void RendeViewport()
		{
			this->renderViewport();
		}
	private:
		void renderViewport()
		{
			ImGui::Begin("Viewport");
			ImGui::End();
		}
	};
}