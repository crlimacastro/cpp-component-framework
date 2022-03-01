#include "pch.h"
#include "Application.h"

#include "Window.h"
#include "SceneManager.h"

#include "Cursor.h"

void rfe::Application::Start()
{
    Window::Get().Open();
    SetExitKey(stopKey);
    OnStart();
    while (!Window::Get().ShouldClose())
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
        return Window::Get().GetMonitor().GetRefreshRate();
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
        SetTargetFPS(Window::Get().GetMonitor().GetRefreshRate());
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

void rfe::Application::Update()
{
    BeginDrawing();
    ClearBackground(clearColor);
    DrawFPS(20, 20);
    SceneManager::GetCurrentScene()->Update();
    EndDrawing();
}

void rfe::Application::Stop()
{
    Window::Get().Close();
}