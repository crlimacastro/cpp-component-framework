#include "pch.h"
#include "Application.h"

#include "Window.h"
#include "SceneManager.h"

#include "Cursor.h"

void rfe::Application::Start()
{
	Window::Open();
	SetExitKey(stopKey);
	OnStart();
	while (!Window::ShouldClose())
	{
		Update();
	}

	Stop();
}

const Color& rfe::Application::GetClearColor() const
{
	return clearColor;
}

void rfe::Application::SetClearColor(const Color& value)
{
	clearColor = value;
}

int rfe::Application::GetTargetFPS() const
{
	if (vsync)
	{
		return Window::GetMonitor().GetRefreshRate();
	}

	return targetFPS;
}

void rfe::Application::TargetFPS(int value)
{
	targetFPS = value;

	if (!vsync)
	{
		SetTargetFPS(value);
	}
}

bool rfe::Application::HasVsync() const
{
	return vsync;
}

void rfe::Application::SetVsync(bool value)
{
	vsync = value;
	if (vsync)
	{
		SetTargetFPS(Window::GetMonitor().GetRefreshRate());
	}
	else
	{
		SetTargetFPS(targetFPS);
	}
}

int rfe::Application::GetStopKey() const
{
	return stopKey;
}

void rfe::Application::SetStopKey(int value)
{
	stopKey = value;
	SetExitKey(value);
}

#include "Clipboard.h"

void rfe::Application::Update()
{
	BeginDrawing();
	ClearBackground(clearColor);

	if (SceneManager::GetCurrentScene())
	{
		SceneManager::GetCurrentScene()->Update();
	}

	EndDrawing();
}

void rfe::Application::Stop()
{
	Window::Close();
}