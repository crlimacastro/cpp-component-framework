#pragma once

namespace rfe {
	struct v2f;

	class Monitor;

	namespace Window
	{
		RFE_API void Open();
		RFE_API bool ShouldClose();
		RFE_API void Close();
		// Whether the Window has been Opened and initialized
		RFE_API bool IsOpen();

		// Visibility Logic
		RFE_API bool IsHidden();
		RFE_API void SetIsHidden(bool value);
		RFE_API bool IsDecorated();
		RFE_API void SetIsDecorated(bool value);
		RFE_API bool IsResizable();
		RFE_API void SetIsResizable(bool value);
		// Returns if Window has been resized last frame
		RFE_API bool IsResized();
		RFE_API bool IsMaximized();
		RFE_API void SetIsMaximized(bool value);
		RFE_API void Maximize();
		RFE_API bool IsMinimized();
		RFE_API void SetIsMinimized(bool value);
		RFE_API void Minimize();
		RFE_API void Restore();
		RFE_API bool IsFocused();
		RFE_API void SetIsFocused(bool value);
		RFE_API bool IsAlwaysOnTop();
		RFE_API void SetIsAlwaysOnTop(bool value);
		RFE_API bool IsFullScreen();
		RFE_API void SetFullScreen(bool value);
		RFE_API void ToggleFullScreen();

		// Icon/Title/Position Logic

		RFE_API const ref<Image> GetIcon();
		RFE_API void SetIcon(ref<Image> value);
		RFE_API std::string GetTitle();
		RFE_API void SetTitle(std::string value);
		RFE_API v2f GetPosition();
		RFE_API void SetPosition(const v2f& value);

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

		RFE_API ref<Monitor> GetMonitor();
		RFE_API void SetMonitor(int value);

		// DPI Logic

		RFE_API v2f GetScaleDPI();
	}
}