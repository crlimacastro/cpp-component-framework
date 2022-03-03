#include "pch.h"
#include "Window.h"

std::shared_ptr<Image> icon;
const char* title = "Raylib Fae Engine App";
rfe::Window::WindowSize size{ 1280, 1024 };
rfe::Window::WindowSize minSize{ 640, 480 };

void rfe::Window::Open()
{
    // If there is a window already open close it
    if (GetWindowHandle())
        CloseWindow();

    InitWindow(size.width, size.height, title);
}

bool rfe::Window::ShouldClose()
{
    return WindowShouldClose();
}

void rfe::Window::Close()
{
    // If there is no window or it has already been closed return
    if (!GetWindowHandle())
        return;

    CloseWindow();
}

bool rfe::Window::IsOpen()
{
    return GetWindowHandle();
}

bool rfe::Window::IsReady()
{
    return IsWindowReady();
}

bool rfe::Window::IsHidden()
{
    return IsWindowHidden();
}

bool rfe::Window::IsMinimized()
{
    return IsWindowMinimized();
}

bool rfe::Window::IsMaximized()
{
    return IsWindowMaximized();
}

bool rfe::Window::IsFocused()
{
    return IsWindowFocused();
}

bool rfe::Window::IsResized()
{
    return IsWindowResized();
}

bool rfe::Window::IsFullScreen()
{
    return IsWindowFullscreen();
}

void rfe::Window::SetFullScreen(bool value)
{
    if (value && !IsWindowFullscreen())
    {
        ToggleFullScreen();
    }
    else if (!value && IsWindowFullscreen())
    {
        ToggleFullScreen();
    }
}

void rfe::Window::ToggleFullScreen()
{
    ToggleFullscreen();
}

void rfe::Window::Maximize()
{
    MaximizeWindow();
}

void rfe::Window::Minimize()
{
    MinimizeWindow();
}

void rfe::Window::Restore()
{
    RestoreWindow();
}

const std::shared_ptr<Image> rfe::Window::GetIcon()
{
    return icon;
}

void rfe::Window::SetIcon(const Image& value)
{
    icon = std::make_shared<Image>(value);
    SetWindowIcon(value);
}

const char* rfe::Window::GetTitle()
{
    return title;
}

void rfe::Window::SetTitle(const char* value)
{
    title = value;
    SetWindowTitle(value);
}

rfe::Vector2D<float> rfe::Window::GetPosition()
{
    Vector2 position = GetWindowPosition();
    return Vector2D<float>{position.x, position.y};
}

void rfe::Window::SetPosition(const Vector2D<int>& value)
{
    SetWindowPosition(value.x, value.y);
}

const rfe::Window::WindowSize& rfe::Window::GetSize()
{
    return size;
}

void rfe::Window::SetSize(int width, int height)
{
    width = std::max(width, 0);
    height = std::max(height, 0);
    size = WindowSize{ width, height };
    SetWindowSize(width, height);
}

int rfe::Window::GetWidth()
{
    return size.width;
}

void rfe::Window::SetWidth(int value)
{
    value = std::max(value, 0);
    size.width = value;
    SetWindowSize(value, GetScreenHeight());
}

int rfe::Window::GetHeight()
{
    return size.height;
}

void rfe::Window::SetHeight(int value)
{
    value = std::max(value, 0);
    size.height = value;
    SetWindowSize(GetScreenWidth(), value);
}

const rfe::Window::WindowSize& rfe::Window::GetMinSize()
{
    return minSize;
}

void rfe::Window::SetMinSize(int width, int height)
{
    width = std::max(width, 0);
    height = std::max(height, 0);
    minSize = WindowSize{ width, height };
    SetWindowMinSize(width, height);
}

int rfe::Window::GetMinWidth()
{
    return minSize.width;
}

void rfe::Window::SetMinWidth(int value)
{
    value = std::max(value, 0);
    minSize.width = value;
    SetWindowMinSize(value, minSize.height);
}

int rfe::Window::GetMinHeight()
{
    return minSize.height;
}

void rfe::Window::SetMinHeight(int value)
{
    value = std::max(value, 0);
    minSize.height = value;
    SetWindowMinSize(minSize.width, value);
}

std::shared_ptr<rfe::Monitor> rfe::Window::GetMonitor()
{
    return Monitor::Get(GetCurrentMonitor());
}

void rfe::Window::SetMonitor(int value)
{
    SetWindowMonitor(value);
}

rfe::Vector2D<float> rfe::Window::GetScaleDPI()
{
    Vector2 scaleDPI = GetWindowScaleDPI();
    return Vector2D<float>{scaleDPI.x, scaleDPI.y};
}