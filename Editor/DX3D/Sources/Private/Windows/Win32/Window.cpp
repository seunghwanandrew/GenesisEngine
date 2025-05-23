#include <Windows\Window.h>
#include <Windows.h>

static LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, Msg, wParam, lParam);
		break;
	}
}

DX3D::Window::Window(const WindowDesc& Desc)
	: Base(Desc.Base), m_WindowSize(Desc.WindowSize)
{
	auto GenerateWindowClassFunc = []()
		{
			WNDCLASSEX WndClass{};
			WndClass.cbSize = sizeof(WNDCLASSEX);
			WndClass.lpszClassName = L"Genesis Game Engine Window";
			WndClass.lpfnWndProc = &WindowProcedure;

			return RegisterClassEx(&WndClass);
		};

	static const auto WindowClassId = std::invoke(GenerateWindowClassFunc);

	if (!WindowClassId)
	{
		DX3DLogAndThrow(Logger::LogLevel::Error, "Fail To Register ClassEx");
	}

	RECT Rec{ 0, 0, m_WindowSize.Width, m_WindowSize.Height };
	AdjustWindowRect(&Rec, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);
	
	m_Handle = CreateWindowEx(NULL, MAKEINTATOM(WindowClassId), L"Genesis Game Engine", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
		CW_USEDEFAULT, CW_USEDEFAULT, Rec.right - Rec.left, Rec.bottom - Rec.top, NULL, NULL, NULL, NULL);

	if (!m_Handle)
	{
		DX3DLogAndThrow(Logger::LogLevel::Error, "Fail To Create WindowEx");
	}

	ShowWindow(static_cast<HWND>(m_Handle), SW_SHOW);
}

DX3D::Window::~Window()
{
	DestroyWindow(static_cast<HWND>(m_Handle));
}
