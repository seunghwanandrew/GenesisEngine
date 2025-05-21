#pragma once
#include <Core/Base.h>

namespace DX3D
{
	class Window : public Base
	{
	public:
		Window();
		virtual ~Window() override;

	private:
		void* m_Handle{};
	};
}


