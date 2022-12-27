#pragma once

// Copy/Paste Clipboard Logic
namespace rfe::Clipboard
{
	RFE_API std::string GetText();
	RFE_API void SetText(std::string value);
}