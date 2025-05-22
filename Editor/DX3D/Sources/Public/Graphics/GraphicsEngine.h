#pragma once
#include <Core/Base.h>
#include <Core/Core.h>

namespace DX3D
{
	class GraphicsEngine final : public Base
	{
	public:
		explicit GraphicsEngine(const GraphicsEngineDesc& Desc);
		virtual ~GraphicsEngine() override;

	private:
		std::unique_ptr<RenderSystem> m_RenderSystem{};
	};
}


