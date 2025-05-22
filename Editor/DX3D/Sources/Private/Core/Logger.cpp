#include <Core/Logger.h>
#include <iostream>

DX3D::Logger::Logger(LogLevel LogLevel) : m_LogLevel(LogLevel)
{
	std::clog << "|| Genesis Game Developers ||" << "\n";
	std::clog << "-----------------------------" << "\n";
}

void DX3D::Logger::Log(LogLevel Level, const char* Message) const
{
	auto LogLevelToString = [](LogLevel Level)
		{
			switch (Level)
			{
			case DX3D::Logger::LogLevel::Error:
				return "Error";
				break;
			case DX3D::Logger::LogLevel::Warning:
				return "Warning";
				break;
			case DX3D::Logger::LogLevel::Infomation:
				return "Infomation";
				break;
			default:
				return "UnKnown";
				break;
			}
		};

	if (Level > m_LogLevel) return;

	std::clog << "[DX3D " << LogLevelToString(Level) << "] : " << Message << "\n";
}
