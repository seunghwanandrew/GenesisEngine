#include <Graphics/GraphicsEngine.h>
#include <Graphics/RenderSystem.h>

DX3D::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& Desc)
	: Base(Desc.Base)
{
	m_RenderSystem = std::make_shared<RenderSystem>(RenderSystemDesc{m_Logger});
}

DX3D::GraphicsEngine::~GraphicsEngine()
{
}

DX3D::RenderSystem& DX3D::GraphicsEngine::GetRenderSystem() const noexcept
{
	return *m_RenderSystem;
}
