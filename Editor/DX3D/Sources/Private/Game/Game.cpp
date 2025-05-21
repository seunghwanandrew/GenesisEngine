#include <Game/Game.h>
#include <Windows/Window.h>

DX3D::Game::Game()
{
	m_Display = std::make_unique<Window>();
}

DX3D::Game::~Game()
{
}

