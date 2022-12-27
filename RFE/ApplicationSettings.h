#pragma once
#include "color.h"
namespace rfe
{
	class RFE_API ApplicationSettings
	{
	public:
		const color& GetClearColor() const;
		void SetClearColor(const color& value);
		int GetTargetFPS() const;
		// Set to define at what FPS the Application will try to run. Set to -1 to let Application run as fast as possible.
		// (Remember if vsync is on, Application will just keep running at Monitor Refresh Rate.
		void TargetFPS(int value);
		bool HasVsync() const;
		// Enable to set FPS to Monitor Refresh Rate.
		void SetVsync(bool value);
		int GetForceStopKey() const;
		void SetForceStopKey(int value);

	private:
		color clearColor = color::RayWhite();
		int targetFPS = -1;
		int forceStopKey = KEY_NULL;
	};
}