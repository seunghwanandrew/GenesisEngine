#pragma once
#include <Core/Base.h>

namespace DX3D
{
	class Window : public Base
	{
	public:
		explicit Window(const WindowDesc& Desc);
		virtual ~Window() override;

	protected:
		void* m_Handle{};
		Rect m_WindowSize{};
	};
}


