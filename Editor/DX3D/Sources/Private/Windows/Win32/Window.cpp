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

DX3D::Window::Window()
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
		throw std::runtime_error("Fail To Register ClassEx");
	}

	RECT Rec{ 0, 0, 1280, 720 };
	AdjustWindowRect(&Rec, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);
	
	m_Handle = CreateWindowEx(NULL, MAKEINTATOM(WindowClassId), L"Genesis Game Engine", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
		CW_USEDEFAULT, CW_USEDEFAULT, Rec.right - Rec.left, Rec.bottom - Rec.top, NULL, NULL, NULL, NULL);

	if (!m_Handle)
	{
		throw std::runtime_error("Fail To Create WindowEx");
	}

	ShowWindow(static_cast<HWND>(m_Handle), SW_SHOW);
}

DX3D::Window::~Window()
{
	DestroyWindow(static_cast<HWND>(m_Handle));
}
