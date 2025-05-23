#pragma once
#include <Graphics/GraphicsResources.h>
#include <wrl.h>

namespace DX3D
{
	class SwapChain final : public GraphicsResources
	{
	public:
		SwapChain(const SwapChainDesc& Desc, const GraphicsResourcesDesc& gDesc);

	private:
		Microsoft::WRL::ComPtr<IDXGISwapChain> m_SwapChain{};
	};
}


