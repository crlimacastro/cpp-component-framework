// File named Time.hpp to avoid name collisions with any Time.h
#pragma once

namespace rfe::Time
{
	// Get time between frames
	RFE_API float GetDeltaTime();
	// Get time since the application started
	RFE_API float GetElapsedTime();
}