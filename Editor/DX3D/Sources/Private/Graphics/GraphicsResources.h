#pragma once
#include <Core/Base.h>
#include <Core/Common.h>

namespace DX3D
{
	class GraphicsResources : public Base
	{
	public:
		explicit GraphicsResources(const GraphicsResourcesDesc& Desc);

	protected:
		std::shared_ptr<const RenderSystem> m_RenderSystemPtr;
		ID3D11Device& m_D3DDevice;
		IDXGIFactory& m_DXGIFactory;
	};
}


