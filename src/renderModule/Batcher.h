﻿#pragma once
#include "glm.hpp"
#include <map>
#include <set>
#include <unordered_set>
#include <vector>

#include "modelModule/Mesh.h"

struct DrawObject {
	friend bool operator==(const DrawObject& lhs, unsigned VAO) {
		return lhs.VAO == VAO;
	}
	friend bool operator!=(const DrawObject& lhs, unsigned VAO) {
		return !(lhs == VAO);
	}

	friend bool operator==(const DrawObject& lhs, const DrawObject& rhs) {
		return lhs.VAO == rhs.VAO;
	}

	friend bool operator!=(const DrawObject& lhs, const DrawObject& rhs) {
		return !(lhs == rhs);
	}

	unsigned VAO;
	size_t verticesCount;
	size_t indicesCount;
	std::vector<GameEngine::ModelModule::MeshTexture> textures;
	std::vector<glm::mat4> transforms;

	bool transparentForShadow = false;
	glm::vec3 sortedPos;
	void sortTransformAccordingToView(const glm::vec3& viewPos);
};


class Batcher {
public:
	Batcher();
	void addToDrawList(unsigned VAO, size_t vertices, size_t indices, std::vector<GameEngine::ModelModule::MeshTexture> textures, glm::mat4 transform, bool transparentForShadow);
	void flushAll(bool clear = false, const glm::vec3& viewPos = {}, bool shadowMap = false);

	std::vector<DrawObject> drawList;

	unsigned instanceVBO = -1;
	unsigned maxDrawSize = 100000;
	unsigned ssboModelMatrices;
};
