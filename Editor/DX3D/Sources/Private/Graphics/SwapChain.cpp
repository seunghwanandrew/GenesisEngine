#include "SwapChain.h"

DX3D::SwapChain::SwapChain(const SwapChainDesc& Desc, const GraphicsResourcesDesc& gDesc)
	: GraphicsResources(gDesc)
{
	DXGI_SWAP_CHAIN_DESC SwapChainDesc{};
	SwapChainDesc.BufferDesc.Width = Desc.WindowSize.Width;
	SwapChainDesc.BufferDesc.Height = Desc.WindowSize.Height;
	SwapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;	
	SwapChainDesc.BufferCount = 2;
	SwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

	SwapChainDesc.OutputWindow = static_cast<HWND>(Desc.HWND);
	SwapChainDesc.SampleDesc.Count = 1;
	SwapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	SwapChainDesc.Windowed = TRUE;

	HRESULT HitResult = gDesc.m_DXGIFactory.CreateSwapChain(&gDesc.m_D3DDevice, &SwapChainDesc, &m_SwapChain);

	DX3DGraphicsLogAndThrow(HitResult, Logger::LogLevel::Error, "Failed To Retrieve IDXGISwapChain");
}
