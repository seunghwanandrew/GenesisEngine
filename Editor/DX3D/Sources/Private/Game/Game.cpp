#include <Game/Game.h>
#include <Windows/Window.h>
#include <Graphics/GraphicsEngine.h>
#include <Core/Logger.h>

DX3D::Game::Game(const GameDesc& Desc)
	: Base({ *std::make_unique<Logger>(Desc.LogLevel).release() }),
	m_LoggerPtr(&m_Logger)
{
	m_GraphicsEngine = std::make_unique<GraphicsEngine>(GraphicsEngineDesc{m_Logger});
	m_Display = std::make_unique<Window>(WindowDesc{m_Logger});

	m_LoggerPtr->Log(Logger::LogLevel::Infomation, "Game Initialized.");
}

DX3D::Game::~Game()
{
	m_LoggerPtr->Log(Logger::LogLevel::Infomation, "Game Finalized.");
}

