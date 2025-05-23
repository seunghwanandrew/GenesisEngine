#pragma once
#include <Core/Base.h>
#include <d3d11.h>
#include <wrl.h>

namespace DX3D
{
	class RenderSystem final : public Base, public std::enable_shared_from_this<RenderSystem>
	{
	public:
		explicit RenderSystem(const RenderSystemDesc& Desc);
		virtual ~RenderSystem() override;

		std::shared_ptr<SwapChain> CreateSwapChain(const SwapChainDesc& Desc) const;

	private:
		// For Clear Definition Method Name Changed From GetGraphicsResourcesDesc() To SetGraphicsResourcesDesc()
		GraphicsResourcesDesc SetGraphicsResourcesDesc() const noexcept;

	private:
		Microsoft::WRL::ComPtr<ID3D11Device> m_D3DDevice{};
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_D3DDeviceContext{};
				
		Microsoft::WRL::ComPtr<IDXGIDevice> m_DXGIDevice{};
		Microsoft::WRL::ComPtr<IDXGIAdapter> m_DXGIAdapter{};
		Microsoft::WRL::ComPtr<IDXGIFactory> m_DXGIFactory{};
	};
}


