#include "pch.h"
#include "Screenshot.hpp"

#include <filesystem>
#include "Application.hpp"

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
