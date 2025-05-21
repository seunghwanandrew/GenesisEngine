#pragma once
#include <Core/Base.h>
#include <Core/Core.h>

namespace DX3D
{
	class Game : public Base
	{
	public:
		Game();
		virtual ~Game() override;

		virtual void Run() final;

	private:
		std::unique_ptr<Window> m_Display{};
		bool m_IsRunning{ true };
	};
}


