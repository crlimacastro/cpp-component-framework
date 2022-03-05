#pragma once

namespace rfe {
	template <typename T>
	struct Vector2D;

	class Monitor;

	namespace Window
	{
		RFE_API void Open();
		RFE_API bool ShouldClose();
		RFE_API void Close();

		// Visibility Logic
		RFE_API bool IsOpen();
		RFE_API bool IsHidden();
		RFE_API bool IsMinimized();
		RFE_API bool IsMaximized();
		RFE_API bool IsFocused();
		// Returns if Window has been resized last frame
		RFE_API bool IsResized();
		RFE_API bool IsFullScreen();
		RFE_API void SetFullScreen(bool value);
		RFE_API void ToggleFullScreen();
		RFE_API void Maximize();
		RFE_API void Minimize();
		RFE_API void Restore();

		// Icon/Title/Position Logic
		RFE_API const std::shared_ptr<Image> GetIcon();
		RFE_API void SetIcon(const std::shared_ptr<Image>& value);
		RFE_API const char* GetTitle();
		RFE_API void SetTitle(const char* value);
		RFE_API Vector2D<float> GetPosition();
		RFE_API void SetPosition(const Vector2D<int>& value);

		// Sizing Logic
		struct RFE_API WindowSize
		{
			int width;
			int height;
		};
		RFE_API const WindowSize& GetSize();
		RFE_API void SetSize(int width, int height);
		RFE_API int GetWidth();
		RFE_API void SetWidth(int value);
		RFE_API int GetHeight();
		RFE_API void SetHeight(int value);
		RFE_API const WindowSize& GetMinSize();
		RFE_API void SetMinSize(int width, int height);
		RFE_API int GetMinWidth();
		RFE_API void SetMinWidth(int value);
		RFE_API int GetMinHeight();
		RFE_API void SetMinHeight(int value);

		// Monitor Logic
		RFE_API std::shared_ptr<Monitor> GetMonitor();
		RFE_API void SetMonitor(int value);

		// DPI Logic
		RFE_API Vector2D<float> GetScaleDPI();
	}
}