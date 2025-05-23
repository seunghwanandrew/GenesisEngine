#include <Game/Game.h>
#include <Game/Display.h>
#include <Graphics/GraphicsEngine.h>
#include <Core/Logger.h>

DX3D::Game::Game(const GameDesc& Desc)
	: Base( BaseDesc{ *std::make_unique<Logger>(Desc.LogLevel).release() }),
	m_LoggerPtr(&m_Logger)
{
	m_GraphicsEngine = std::make_unique<GraphicsEngine>(GraphicsEngineDesc{m_Logger});
	m_Display = std::make_unique<Display>(DisplayDesc{ WindowDesc{m_Logger, Desc.m_WindowSize}, m_GraphicsEngine->GetRenderSystem()});

	DX3DLog(Logger::LogLevel::Information, "Game Initialized.");
}

DX3D::Game::~Game()
{
	DX3DLog(Logger::LogLevel::Information, "Game Finalized.");
}

