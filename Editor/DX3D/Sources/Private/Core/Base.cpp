#include <Core/Base.h>

DX3D::Base::Base(const BaseDesc& Desc) : m_Logger(Desc.Logger)
{
}

DX3D::Base::~Base()
{
}

DX3D::Logger& DX3D::Base::GetLogger() const noexcept
{
	return m_Logger;
}
