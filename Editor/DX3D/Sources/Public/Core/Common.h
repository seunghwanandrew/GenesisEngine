#pragma once
#include <Core/Core.h>
#include <Core/Logger.h>
#include <Math/Rect.h>
#include <d3d11.h>

namespace DX3D
{
	struct BaseDesc
	{
		Logger& Logger;
	};

	struct WindowDesc
	{
		BaseDesc Base;
		Rect WindowSize{};
	};

	struct DisplayDesc
	{
		WindowDesc Window;
		RenderSystem& RenderSystem;
	};

	struct GraphicsEngineDesc
	{
		BaseDesc Base;
	};

	struct RenderSystemDesc
	{
		BaseDesc Base;
	};

	struct SwapChainDesc
	{
		void* HWND{}; // Window Handle;
		Rect WindowSize{};
	};

	struct GraphicsResourcesDesc
	{
		BaseDesc Base;
		std::shared_ptr<const RenderSystem> m_RenderSystemPtr;
		ID3D11Device& m_D3DDevice;
		IDXGIFactory& m_DXGIFactory;
	};

	struct GameDesc
	{
		Rect m_WindowSize{ 1280,720 };
		Logger::LogLevel LogLevel = Logger::LogLevel::Error;
	};
}