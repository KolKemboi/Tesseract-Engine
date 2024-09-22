#pragma once

#include "TsrtUI.h"
#include <glad/glad.h>

namespace TsrtUI
{
	class Viewport
	{
	public:
		//Inputs a framebuffer object which will be rendered onto the viewport window.
		void RendeViewport()
		{
			this->renderViewport();
		}
	private:
		void renderViewport()
		{
			ImGui::Begin("Viewport");
			//Where I render the framebuffer
			ImGui::End();
		}
	};
}