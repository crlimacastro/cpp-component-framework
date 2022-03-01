#pragma once

#include "Vector2D.h"
#include "Monitor.h"

namespace rfe
{
	// Singleton for Window functionality
	class RFE_API Window
	{
	public:
		static Window& Get();
		void Open() const;
		bool ShouldClose() const;
		void Close() const;

		// Visibility Logic
	public:
		bool IsOpen() const;
		bool IsReady() const;
		bool IsHidden() const;
		bool IsMinimized() const;
		bool IsMaximized() const;
		bool IsFocused() const;
		// Returns if Window has been resized last frame
		bool IsResized() const;
		bool IsFullScreen() const;
		void SetFullScreen(bool value) const;
		void ToggleFullScreen() const;
		void Maximize() const;
		void Minimize() const;
		void Restore() const;

		// State Logic
	public:
		bool IsState(unsigned int flag) const;
		void SetState(unsigned int flags) const;
		void ClearState(unsigned int flags) const;

		// Icon/Title/Position Logic
	public:
		const Image& GetIcon() const;
		void SetIcon(const Image& value);
		const char* GetTitle() const;
		void SetTitle(const char* value);
		Vector2D<float> GetPosition() const;
		void SetPosition(const Vector2D<int>& value) const;

		// Sizing Logic
	public:
		struct WindowSize
		{
			int width;
			int height;
		};
		const WindowSize& GetSize() const;
		void SetSize(int width, int height);
		int GetWidth() const;
		void SetWidth(int value);
		int GetHeight() const;
		void SetHeight(int value);
		const WindowSize& GetMinSize() const;
		void SetMinSize(int width, int height);
		int GetMinWidth() const;
		void SetMinWidth(int value);
		int GetMinHeight() const;
		void SetMinHeight(int value);

		// Monitor Logic
	public:
		const Monitor GetMonitor() const;
		void SetMonitor(int value) const;

		// DPI Logic
	public:
		Vector2D<float> GetScaleDPI() const;

	private:
		Window();
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;
		~Window();

		std::shared_ptr<Image> icon;
		const char* title = "Raylib Fae Engine App";
		WindowSize size{ 1280, 1024 };
		WindowSize minSize{ 640, 480 };
	};
}