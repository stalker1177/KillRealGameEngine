﻿#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Batcher.h"

namespace GameEngine::RenderModule {
	class Renderer {
	public:
		void draw();
		void postDraw();
		void init();
		void terminate() const;

		Batcher* getBatcher() { return mBatcher;};

		static void drawArrays(GLenum mode, GLsizei size, GLint first = 0);
		static void drawElements(GLenum mode, GLsizei size, GLenum type, const void* place = nullptr);
		static void drawElementsInstanced(GLenum mode, GLsizei size, GLenum type, GLsizei instancesCount, const void* place = nullptr);
		static void drawArraysInstancing(GLenum mode, GLsizei size, GLsizei instancesCount, GLint first = 0);

		inline static int SCR_WIDTH = 1920;
		inline static int SCR_HEIGHT = 1080;
		inline static size_t mDrawCallsCount = 0;
		inline static size_t mDrawVerticesCount = 0;
	private:
		Batcher* mBatcher = nullptr;
	public:
		static GLFWwindow* initGLFW();
	private:
		inline static bool mGLFWInited = false;
	};
}

