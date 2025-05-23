#include <Game/Display.h>
#include <Graphics/RenderSystem.h>

DX3D::Display::Display(const DisplayDesc& Desc)
	: Window(Desc.Window)
{
	m_SwapChain = Desc.RenderSystem.CreateSwapChain({ m_Handle, m_WindowSize });
}
