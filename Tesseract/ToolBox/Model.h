#pragma once

#include "../tspch.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.h"

namespace Tsrt
{
	class Model
	{
	public:
		std::vector <Mesh> m_meshes;
		Model(std::string const& path, const char* vertexPath, const char* fragmentPath);
		void DrawModel();

	private:
		const char* m_vertexPath;
		const char* m_fragmentPath;
		void loadModel(std::string const& path);
		void processNode(aiNode* node, const aiScene* scene);
		Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	};
}