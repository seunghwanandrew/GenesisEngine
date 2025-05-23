#include <Graphics/RenderSystem.h>

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

}

DX3D::RenderSystem::~RenderSystem()
{
}
