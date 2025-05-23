#pragma once
#include <Windows/Window.h>

namespace DX3D
{
	class Display final : public Window
	{
	public:
		explicit Display(const DisplayDesc& Desc);

	private:
		std::shared_ptr<SwapChain> m_SwapChain;
	};
}


