#pragma once

// Copy/Paste Clipboard Logic
namespace rfe::Clipboard
{
	RFE_API const char* GetText();
	RFE_API void SetText(const char* value);
}