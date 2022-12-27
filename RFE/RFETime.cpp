#include "pch.h"
#include "RFETime.h"

float rfe::Time::GetDeltaTime()
{
	return GetFrameTime();
}

float rfe::Time::GetElapsedTime()
{
	return GetTime();
}
