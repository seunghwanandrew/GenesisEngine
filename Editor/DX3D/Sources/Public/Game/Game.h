#pragma once
#include <Core/Base.h>
#include <Core/Core.h>

namespace DX3D
{
	class Game : public Base
	{
	public:
		explicit Game(const GameDesc& Desc);
		virtual ~Game() override;

		virtual void Run() final;

	private:
		std::unique_ptr<Logger> m_LoggerPtr{};
		std::unique_ptr<GraphicsEngine> m_GraphicsEngine{};
		std::unique_ptr<Display> m_Display{};
		bool m_IsRunning{ true };
	};
}


