#include <Graphics/GraphicsEngine.h>
#include <Graphics/RenderSystem.h>

DX3D::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& Desc)
	: Base(Desc.Base)
{
	m_RenderSystem = std::make_unique<RenderSystem>(RenderSystemDesc{m_Logger});
}

DX3D::GraphicsEngine::~GraphicsEngine()
{
}
