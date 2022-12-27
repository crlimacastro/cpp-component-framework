#include "pch.h"
#include "Screenshot.h"

#include <filesystem>
#include "Application.h"

void rfe::Screenshot::SaveScreenshot(std::string fileName)
{
	if (!DirectoryExists("screenshots"))
	{
		std::filesystem::create_directory("screenshots");
	}

	if (Application::GetActive())
	{
		TakeScreenshot(("screenshots/" + fileName).c_str());
	}
}
