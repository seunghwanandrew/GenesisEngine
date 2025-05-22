#pragma once
#include <Core/Base.h>
#include <d3d11.h>
#include <wrl.h>

namespace DX3D
{
	class RenderSystem final : public Base
	{
	public:
		explicit RenderSystem(const RenderSystemDesc& Desc);
		virtual ~RenderSystem() override;

	private:
		Microsoft::WRL::ComPtr<ID3D11Device> m_D3DDevice{};
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_D3DDeviceContext{};
	};
}


