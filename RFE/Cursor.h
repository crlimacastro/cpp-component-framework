#pragma once

// Mouse Cursor
namespace rfe::Cursor
{
	RFE_API void Show();
	RFE_API void Hide();
	RFE_API bool IsVisible();
	RFE_API void ToggleVisible();
	RFE_API void Enable();
	RFE_API void Disable();
	RFE_API bool IsOnScreen();
}