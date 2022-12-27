#pragma once

namespace rfe::Screenshot
{
	// Takes a screenshot of current screen (filename extension defines format)
	// Remember to call after draw calls if you want the screenshot to reflect the visual state of the app post draw
	RFE_API void SaveScreenshot(std::string fileName);
}