#include "pch.h"
#include "Window.h"

rfe::Window& rfe::Window::Get()
{
    static Window instance;
    return instance;
}

void rfe::Window::Open() const
{
    // If there is a window already open close it
    if (GetWindowHandle())
        CloseWindow();

    InitWindow(size.width, size.height, title);
}

bool rfe::Window::ShouldClose() const
{
    return WindowShouldClose();
}

void rfe::Window::Close() const
{
    // If there is no window or it has already been closed return
    if (!GetWindowHandle())
        return;

    CloseWindow();
}

bool rfe::Window::IsOpen() const
{
    return GetWindowHandle();
}

bool rfe::Window::IsReady() const
{
    return IsWindowReady();
}

bool rfe::Window::IsHidden() const
{
    return IsWindowHidden();
}

bool rfe::Window::IsMinimized() const
{
    return IsWindowMinimized();
}

bool rfe::Window::IsMaximized() const
{
    return IsWindowMaximized();
}

bool rfe::Window::IsFocused() const
{
    return IsWindowFocused();
}

bool rfe::Window::IsResized() const
{
    return IsWindowResized();
}

bool rfe::Window::IsFullScreen() const
{
    return IsWindowFullscreen();
}

void rfe::Window::SetFullScreen(bool value) const
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

void rfe::Window::ToggleFullScreen() const
{
    ToggleFullscreen();
}

void rfe::Window::Maximize() const
{
    MaximizeWindow();
}
void rfe::Window::Minimize() const
{
    MinimizeWindow();
}
void rfe::Window::Restore() const
{
    RestoreWindow();
}

bool rfe::Window::IsState(unsigned int flag) const
{
    return IsWindowState(flag);
}

void rfe::Window::SetState(unsigned int flags) const
{
    SetWindowState(flags);
}

void rfe::Window::ClearState(unsigned int flags) const
{
    ClearWindowState(flags);
}

const Image& rfe::Window::GetIcon() const
{
    return *icon;
}

void rfe::Window::SetIcon(const Image& value)
{
    icon = std::make_shared<Image>(value);
    SetWindowIcon(value);
}

const char* rfe::Window::GetTitle() const
{
    return title;
}

void rfe::Window::SetTitle(const char* value)
{
    title = value;
    SetWindowTitle(value);
}

rfe::Vector2D<float> rfe::Window::GetPosition() const
{
    Vector2 position = GetWindowPosition();
    return Vector2D<float>{position.x, position.y};
}

void rfe::Window::SetPosition(const Vector2D<int>& value) const
{
    SetWindowPosition(value.x, value.y);
}

const rfe::Window::WindowSize& rfe::Window::GetSize() const
{
    return size;
}

void rfe::Window::SetSize(int width, int height)
{
    size = WindowSize{ width, height };
    SetWindowSize(width, height);
}

int rfe::Window::GetWidth() const
{
    return size.width;
}

void rfe::Window::SetWidth(int value)
{
    size.width = value;
    SetWindowSize(value, GetScreenHeight());
}

int rfe::Window::GetHeight() const
{
    return size.height;
}

void rfe::Window::SetHeight(int value)
{
    size.height = value;
    SetWindowSize(GetScreenWidth(), value);
}

const rfe::Window::WindowSize& rfe::Window::GetMinSize() const
{
    return minSize;
}

void rfe::Window::SetMinSize(int width, int height)
{
    minSize = WindowSize{ width, height };
    SetWindowMinSize(width, height);
}

int rfe::Window::GetMinWidth() const
{
    return minSize.width;
}

void rfe::Window::SetMinWidth(int value)
{
    minSize.width = value;
    SetWindowMinSize(value, minSize.height);
}

int rfe::Window::GetMinHeight() const
{
    return minSize.height;
}

void rfe::Window::SetMinHeight(int value)
{
    minSize.height = value;
    SetWindowMinSize(minSize.width, value);
}

const rfe::Monitor rfe::Window::GetMonitor() const
{
    return Monitor(GetCurrentMonitor());
}

void rfe::Window::SetMonitor(int value) const
{
    SetWindowMonitor(value);
}

rfe::Vector2D<float> rfe::Window::GetScaleDPI() const
{
    Vector2 scaleDPI = GetWindowPosition();
    return Vector2D<float>{scaleDPI.x, scaleDPI.y};
}

rfe::Window::Window()
{
    Open();
}

rfe::Window::~Window()
{
    Close();
}