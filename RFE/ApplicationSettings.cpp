#include "pch.h"
#include "ApplicationSettings.h"

#include "Window.h"

const Color& rfe::Application::Settings::GetClearColor() const
{
	return clearColor;
}

void rfe::Application::Settings::SetClearColor(const Color& value)
{
	clearColor = value;
}

int rfe::Application::Settings::GetTargetFPS() const
{
	if (IsWindowState(FLAG_VSYNC_HINT))
	{
		return Window::GetMonitor()->GetRefreshRate();
	}

	return targetFPS;
}

void rfe::Application::Settings::TargetFPS(int value)
{
	targetFPS = value;

	if (!IsWindowState(FLAG_VSYNC_HINT))
	{
		SetTargetFPS(value);
	}
}

bool rfe::Application::Settings::HasVsync() const
{
	return IsWindowState(FLAG_VSYNC_HINT);
}

void rfe::Application::Settings::SetVsync(bool value)
{
	if (value)
	{
		SetWindowState(FLAG_VSYNC_HINT);
		SetTargetFPS(Window::GetMonitor()->GetRefreshRate());
	}
	else
	{
		ClearWindowState(FLAG_VSYNC_HINT);
		SetTargetFPS(targetFPS);
	}
}

int rfe::Application::Settings::GetForceStopKey() const
{
	return forceStopKey;
}

void rfe::Application::Settings::SetForceStopKey(int value)
{
	forceStopKey = value;
	SetExitKey(value);
}
