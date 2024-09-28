#pragma once

#include "Mesh.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <iostream>

#include "../Shaders/Shader.h"

namespace Mesh
{
	class Model
	{
	public:
		std::vector<TsrtMesh::Mesh> _meshes;


		Model(std::string modelPath);
		void Draw(TsrtShader::Shader& shader);
	private:

		void loadModel(std::string modelPath);
		void processNode(aiNode* node, const  aiScene* scene);
		TsrtMesh::Mesh processMesh(aiMesh* mesh, const aiScene* scene);

	};
}