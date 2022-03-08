#pragma once

// Mouse Cursor
namespace rfe::Cursor
{
	RFE_API enum class Type
	{
		Default = 0,     // Default pointer shape
		Arrow = 1,     // Arrow shape
		IBeam = 2,     // Text writing cursor shape
		Crosshair = 3,     // Cross shape
		PointingHand = 4,     // Pointing hand cursor
		ResizeEW = 5,     // Horizontal resize/move arrow shape
		ResizeNS = 6,     // Vertical resize/move arrow shape
		ResizeNWSE = 7,     // Top-left to bottom-right diagonal resize/move arrow shape
		ResizeNESW = 8,     // The top-right to bottom-left diagonal resize/move arrow shape
		ResizeAll = 9,     // The omni-directional resize/move cursor shape
		NotAllowed = 10     // The operation-not-allowed shape
	};

	RFE_API void Show();
	RFE_API void Hide();
	RFE_API bool IsVisible();
	RFE_API void ToggleVisible();
	RFE_API void Enable();
	RFE_API void Disable();
	RFE_API bool IsOnScreen();
	RFE_API void Set(Type type);
}