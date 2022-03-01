#include "pch.h"
#include "SceneManager.h"

std::shared_ptr<rfe::Scene> rfe::SceneManager::currentScene = nullptr;

std::shared_ptr<rfe::Scene> rfe::SceneManager::GetCurrentScene()
{
    return currentScene;
}