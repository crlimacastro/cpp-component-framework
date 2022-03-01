#pragma once

#include "Scene.h"

namespace rfe
{
	class RFE_API SceneManager
	{
	public:
		static std::shared_ptr<Scene> GetCurrentScene();

		template <typename T>
		static void LoadScene()
		{
			currentScene = std::make_shared<T>();
			currentScene->Load();
		}

	private:
		SceneManager() = default;
		SceneManager(const SceneManager&) = delete;
		SceneManager& operator=(const SceneManager&) = delete;
		static std::shared_ptr<Scene> currentScene;
	};
}

