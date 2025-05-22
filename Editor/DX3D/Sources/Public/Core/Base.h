#pragma once
#include <stdexcept>
#include <Core/Common.h>

namespace DX3D
{
	class Base
	{
	public:
		explicit Base(const BaseDesc& Desc);
		virtual ~Base();

		virtual Logger& GetLogger() const noexcept final;

	protected:
		Base(const Base&) = delete;
		Base(Base&&) = delete;
		Base& operator=(const Base&) = delete;
		Base& operator=(Base&&) = delete;

	protected:
		Logger& m_Logger;
	};
}