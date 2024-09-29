#pragma once

#include "../tspch.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.h"

namespace Tsrt
{
	class TsrtModel
	{
	public:
		TsrtModel(std::string path);
		void ModelDestroyer();
		void DrawModel();

	private:

		void loadModel(std::string path);
		void processNode(aiNode* node, const aiScene* scene);
		TsrtMesh processMesh(aiMesh* mesh, const aiScene* scene);
	};
}