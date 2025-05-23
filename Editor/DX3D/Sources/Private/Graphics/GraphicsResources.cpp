#include "GraphicsResources.h"

DX3D::GraphicsResources::GraphicsResources(const GraphicsResourcesDesc& Desc)
	: Base(Desc.Base), m_RenderSystemPtr(Desc.m_RenderSystemPtr), m_D3DDevice(Desc.m_D3DDevice), m_DXGIFactory(Desc.m_DXGIFactory)
{
}
