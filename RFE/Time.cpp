#include "pch.h"
#include "Time.hpp"

float rfe::Time::GetDeltaTime()
{
	return GetFrameTime();
}

float rfe::Time::GetElapsedTime()
{
	return GetTime();
}
