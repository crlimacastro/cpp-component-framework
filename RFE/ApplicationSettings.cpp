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
	if (vsync)
	{
		return Window::GetMonitor()->GetRefreshRate();
	}

	return targetFPS;
}

void rfe::Application::Settings::TargetFPS(int value)
{
	targetFPS = value;

	if (!vsync)
	{
		SetTargetFPS(value);
	}
}

bool rfe::Application::Settings::HasVsync() const
{
	return vsync;
}

void rfe::Application::Settings::SetVsync(bool value)
{
	vsync = value;
	if (vsync)
	{
		SetTargetFPS(Window::GetMonitor()->GetRefreshRate());
	}
	else
	{
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
