#include <Graphics/RenderSystem.h>
#include <Graphics/SwapChain.h>

DX3D::RenderSystem::RenderSystem(const RenderSystemDesc& Desc)
	: Base(Desc.Base)
{
	D3D_FEATURE_LEVEL FeatureLevel{};
	UINT CreateDeviceFlags{};

#ifdef _DEBUG
	CreateDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	HRESULT HitResult = D3D11CreateDevice(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, CreateDeviceFlags, NULL,
		0, D3D11_SDK_VERSION, &m_D3DDevice, &FeatureLevel, &m_D3DDeviceContext);

	DX3DGraphicsLogAndThrow(HitResult, Logger::LogLevel::Error, "Fail To Direct3D11 Initialization");

	DX3DGraphicsLogAndThrow(m_D3DDevice->QueryInterface(IID_PPV_ARGS(&m_DXGIDevice)), Logger::LogLevel::Error, "Failed To Retrieve DXGIDevice");

	DX3DGraphicsLogAndThrow(m_DXGIDevice->GetParent(IID_PPV_ARGS(&m_DXGIAdapter)), Logger::LogLevel::Error, "Failed To Retrieve DXGIAdapter");

	DX3DGraphicsLogAndThrow(m_DXGIAdapter->GetParent(IID_PPV_ARGS(&m_DXGIFactory)), Logger::LogLevel::Error, "Failed To Retrieve DXGIFactory");
}

DX3D::RenderSystem::~RenderSystem()
{
}

std::shared_ptr<DX3D::SwapChain> DX3D::RenderSystem::CreateSwapChain(const SwapChainDesc& Desc) const
{	
	return std::make_shared<SwapChain>(Desc, GetGraphicsResourcesDesc());
}

DX3D::GraphicsResourcesDesc DX3D::RenderSystem::GetGraphicsResourcesDesc() const noexcept
{
	return GraphicsResourcesDesc{ BaseDesc{m_Logger}, shared_from_this() ,*m_D3DDevice.Get(), *m_DXGIFactory.Get()};
}
