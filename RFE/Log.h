#pragma once

namespace rfe
{
	RFE_API void Log(std::string msg);
}

#ifdef _DEBUG
#define RFE_LOG(msg) rfe::Log(msg)
#else
#define RFE_LOG(msg)
#endif