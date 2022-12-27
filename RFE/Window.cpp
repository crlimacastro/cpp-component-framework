#include "pch.h"
#include "Window.h"

#include "v2f.h"
#include "Monitor.h"

rfe::ref<Image> icon;
std::string title = "Raylib Fae Engine App";
rfe::Window::WindowSize size{ 1280, 1024 };
rfe::Window::WindowSize minSize{ 640, 480 };

void rfe::Window::Open()
{
	// Cannot open the window once it has already been opened once
	if (GetWindowHandle())
		return;

	InitWindow(size.width, size.height, title.c_str());
}

bool rfe::Window::ShouldClose()
{
	return WindowShouldClose();
}

void rfe::Window::Close()
{
	// If there is no window return
	if (!GetWindowHandle())
		return;

	CloseWindow();
}

bool rfe::Window::IsOpen()
{
	return GetWindowHandle();
}

bool rfe::Window::IsHidden()
{
	return IsWindowHidden();
}

void rfe::Window::SetIsHidden(bool value)
{
	value ? SetWindowState(FLAG_WINDOW_HIDDEN) : ClearWindowState(FLAG_WINDOW_HIDDEN);
}

bool rfe::Window::IsDecorated()
{
	return !IsWindowState(FLAG_WINDOW_UNDECORATED);
}

void rfe::Window::SetIsDecorated(bool value)
{
	value ? ClearWindowState(FLAG_WINDOW_UNDECORATED) : SetWindowState(FLAG_WINDOW_UNDECORATED);
}

bool rfe::Window::IsMinimized()
{
	return IsWindowMinimized();
}

void rfe::Window::SetIsMinimized(bool value)
{
	value ? SetWindowState(FLAG_WINDOW_MINIMIZED) : ClearWindowState(FLAG_WINDOW_MINIMIZED);
}

void rfe::Window::Minimize()
{
	MinimizeWindow();
}

bool rfe::Window::IsMaximized()
{
	return IsWindowMaximized();
}

void rfe::Window::SetIsMaximized(bool value)
{
	value ? SetWindowState(FLAG_WINDOW_MAXIMIZED) : ClearWindowState(FLAG_WINDOW_MAXIMIZED);
}

void rfe::Window::Maximize()
{
	MaximizeWindow();
}

bool rfe::Window::IsFocused()
{
	return IsWindowFocused();
}

void rfe::Window::SetIsFocused(bool value)
{
	value ? ClearWindowState(FLAG_WINDOW_UNFOCUSED) : SetWindowState(FLAG_WINDOW_UNFOCUSED);
}

bool rfe::Window::IsAlwaysOnTop()
{
	return IsWindowState(FLAG_WINDOW_TOPMOST);
}

RFE_API void rfe::Window::SetIsAlwaysOnTop(bool value)
{
	value ? SetWindowState(FLAG_WINDOW_TOPMOST) : ClearWindowState(FLAG_WINDOW_TOPMOST);
}

bool rfe::Window::IsResizable()
{
	return IsWindowState(FLAG_WINDOW_RESIZABLE);
}

void rfe::Window::SetIsResizable(bool value)
{
	value ? SetWindowState(FLAG_WINDOW_RESIZABLE) : ClearWindowState(FLAG_WINDOW_RESIZABLE);
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

void rfe::Window::Restore()
{
	RestoreWindow();
}

const rfe::ref<Image> rfe::Window::GetIcon()
{
	return icon;
}

void rfe::Window::SetIcon(ref<Image> value)
{
	icon = value;
	value ? SetWindowIcon(*value) : SetWindowIcon(Image());
}

std::string rfe::Window::GetTitle()
{
	return title;
}

void rfe::Window::SetTitle(std::string value)
{
	title = value;
	SetWindowTitle(value.c_str());
}

rfe::v2f rfe::Window::GetPosition()
{
	Vector2 position = GetWindowPosition();
	return { position.x, position.y };
}

void rfe::Window::SetPosition(const v2f& value)
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

rfe::ref<rfe::Monitor> rfe::Window::GetMonitor()
{
	return Monitor::Get(GetCurrentMonitor());
}

void rfe::Window::SetMonitor(int value)
{
	if (value < 0 || value >= GetMonitorCount()) return;
	SetWindowMonitor(value);
}

rfe::v2f rfe::Window::GetScaleDPI()
{
	return v2f(GetWindowScaleDPI());
}