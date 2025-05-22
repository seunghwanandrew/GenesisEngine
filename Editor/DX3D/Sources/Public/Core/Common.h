#pragma once
#include <Core/Core.h>
#include <Core/Logger.h>

namespace DX3D
{
	struct BaseDesc
	{
		Logger& Logger;
	};

	struct WindowDesc
	{
		BaseDesc Base;
	};

	struct GraphicsEngineDesc
	{
		BaseDesc Base;
	};

	struct RenderSystemDesc
	{
		BaseDesc Base;
	};

	struct GameDesc
	{
		Logger::LogLevel LogLevel = Logger::LogLevel::Error;
	};
}