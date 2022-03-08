#include "pch.h"
#include "Log.hpp"

#include <iostream>

void rfe::LogInfo(std::string msg)
{
	std::cout << "[RFE_LOG] ";
	TraceLog(LOG_INFO, msg.c_str());
}

RFE_API void rfe::LogWarning(std::string msg)
{
	std::cout << "[RFE_LOG] ";
	TraceLog(LOG_WARNING, msg.c_str());
}

RFE_API void rfe::LogError(std::string msg)
{
	std::cout << "[RFE_LOG] ";
	TraceLog(LOG_ERROR, msg.c_str());
}

RFE_API void rfe::LogFatal(std::string msg)
{
	std::cout << "[RFE_LOG] ";
	TraceLog(LOG_FATAL, msg.c_str());
}
