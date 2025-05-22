#pragma once

namespace DX3D
{
	class Logger final
	{
	public:
		enum class LogLevel
		{
			Error = 0,
			Warning,
			Infomation
		};

		explicit Logger(LogLevel LogLevel = LogLevel::Error);

		void Log(LogLevel Level, const char* Message) const;

	private:
		LogLevel m_LogLevel = LogLevel::Error;
	};
}

