#include "pch.h"
#include "ApplicationSettings.h"

#include "Window.h"
#include "Monitor.h"

const rfe::color& rfe::ApplicationSettings::GetClearColor() const
{
	return clearColor;
}

void rfe::ApplicationSettings::SetClearColor(const color& value)
{
	clearColor = value;
}

int rfe::ApplicationSettings::GetTargetFPS() const
{
	if (IsWindowState(FLAG_VSYNC_HINT))
	{
		return Window::GetMonitor()->GetRefreshRate();
	}

	return targetFPS;
}

void rfe::ApplicationSettings::TargetFPS(int value)
{
	targetFPS = value;

	if (!IsWindowState(FLAG_VSYNC_HINT))
	{
		SetTargetFPS(value);
	}
}

bool rfe::ApplicationSettings::HasVsync() const
{
	return IsWindowState(FLAG_VSYNC_HINT);
}

void rfe::ApplicationSettings::SetVsync(bool value)
{
	if (value)
	{
		SetWindowState(FLAG_VSYNC_HINT);
		SetTargetFPS(rfe::Window::GetMonitor()->GetRefreshRate());
	}
	else
	{
		ClearWindowState(FLAG_VSYNC_HINT);
		SetTargetFPS(targetFPS);
	}
}

int rfe::ApplicationSettings::GetForceStopKey() const
{
	return forceStopKey;
}

void rfe::ApplicationSettings::SetForceStopKey(int value)
{
	forceStopKey = value;
	SetExitKey(value);
}