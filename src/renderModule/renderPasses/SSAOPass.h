﻿#pragma once
#include <vec3.hpp>
#include <vector>

#include "renderModule/RenderPass.h"

namespace GameEngine::RenderModule::RenderPasses {
	class SSAOPass : public RenderPass {
	public:
		struct Data {
			std::vector<glm::vec3> mSsaoKernel;
			unsigned int mNoiseTexture;
			unsigned int mSsaoFbo;
			unsigned int mSsaoBlurFbo = 0;
			unsigned int mSsaoColorBuffer = 0;
			unsigned int mSsaoColorBufferBlur = 0;
			int mKernelSize = 64;
			float mRadius = 0.5f;
			float mBias = 0.1f;

			float sigmaS = 0.5f;
			float sigmaL = 0.5f;
		};

		void init();
		void render(Renderer* renderer, SystemsModule::RenderDataHandle& renderDataHandle) override;
	private:
		
		Data mData{};
	};
}