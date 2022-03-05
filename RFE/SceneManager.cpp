#include "pch.h"
#include "SceneManager.hpp"

std::shared_ptr<rfe::Scene> rfe::SceneManager::GetCurrentScene()
{
    return currentScene;
}

void rfe::SceneManager::UnloadScene()
{
	if (currentScene)
	{
		currentScene->Unload();
	}

	currentScene = nullptr;
}
