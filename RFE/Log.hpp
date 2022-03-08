#pragma once

namespace rfe
{
	// Info logging, used for program execution info
	RFE_API void LogInfo(std::string msg);
	// Warning logging, used on recoverable failures
	RFE_API void LogWarning(std::string msg);
	// Error logging, used on unrecoverable failures
	RFE_API void LogError(std::string msg);
	// Fatal logging, used to abort program: exit(EXIT_FAILURE)
	RFE_API void LogFatal(std::string msg);
}

#ifdef _DEBUG
#define RFE_LOG_INFO(msg) rfe::LogInfo(msg)
#define RFE_LOG_WARN(msg) rfe::LogWarning(msg)
#define RFE_LOG_ERROR(msg) rfe::LogError(msg)
#define RFE_LOG_FATAL(msg) rfe::LogFatal(msg)
#else
#define RFE_LOG(msg)
#endif