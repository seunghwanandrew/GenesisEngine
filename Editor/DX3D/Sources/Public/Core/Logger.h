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

#define DX3DLog(LogLevel, Message)\
		{\
			GetLogger().Log(LogLevel, Message);\
		}

#define DX3DLogAndThrow(LogLevel, Message)\
		{\
			DX3DLog(LogLevel, Message);\
			throw std::runtime_error(Message);\
		}

#define DX3DGraphicsLogAndThrow(HitResult, LogLevel, Message)\
		{\
			HRESULT HResult = (HitResult);\
			if (FAILED(HResult)) DX3DLogAndThrow(LogLevel, Message);\
		}
}

