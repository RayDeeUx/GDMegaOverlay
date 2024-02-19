#pragma once

#include <imgui.h>
#include <cocos2d.h>
#include "RenderTexture.h"

namespace Blur
{
    inline cocos2d::CCGLProgram* blurProgram;
	inline std::shared_ptr<RenderTexture> gdRenderTexture;

    inline GLint oldTexture = -1;
    inline GLint darknessUniform = -1;
    inline GLint stepsUniform = -1;
    inline GLint sizeUniform = -1;

    void compileBlurShader();

    void blurWindowBackground();

    void blurCallback(const ImDrawList*, const ImDrawCmd*);
    void resetCallback(const ImDrawList*, const ImDrawCmd*);
};