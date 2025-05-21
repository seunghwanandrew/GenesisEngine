#include <Game/Game.h>
#include <Windows.h>

void DX3D::Game::Run()
{
	MSG Msg{};
	while (m_IsRunning)
	{
		while (PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE))
		{
			while (Msg.message == WM_QUIT)
			{
				m_IsRunning = false;
				break;
			}

			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}

		Sleep(1); // Milli Seconds;
	}
}