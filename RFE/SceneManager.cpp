#include "pch.h"
#include "SceneManager.hpp"

std::shared_ptr<rfe::Scene> rfe::sceneManager::GetCurrentScene()
{
    return currentScene;
}

void rfe::sceneManager::UnloadScene()
{
	if (currentScene)
	{
		currentScene->Unload();
	}

	currentScene = nullptr;
}
