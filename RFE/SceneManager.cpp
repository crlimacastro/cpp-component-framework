#include "pch.h"
#include "SceneManager.h"

rfe::ref<rfe::Scene> rfe::SceneManager::GetCurrentScene()
{
	return currentScene;
}

void rfe::SceneManager::UnloadScene()
{
	if (!currentScene)
		return;

	currentScene->Unload();
	currentScene = nullptr;
}
