﻿#pragma once

namespace GameEngine::ModelModule {
	class Mesh;

	enum class eDrawObjectType {
		CUBE = 0,
		TRIANGLE,
		SQUARE,
		PRIMITIVE_CUBE,
		PRIMITIVE_CUBE_N
	};

	class MeshFactory {
	public:
		static Mesh* createPrimitiveMesh(eDrawObjectType type);
	};


}
