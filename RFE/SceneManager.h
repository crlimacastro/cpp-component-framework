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
			if (currentScene)
			{
				currentScene->Unload();
			}
			currentScene = std::make_shared<T>();
			currentScene->Load();
		}

	private:
		SceneManager() = default;
		SceneManager(const SceneManager& other) = delete;
		SceneManager(SceneManager&& other) = delete ;
		SceneManager& operator=(const SceneManager& other) = delete;
		SceneManager& operator=(SceneManager&& other) noexcept = delete;

		static std::shared_ptr<Scene> currentScene;
	};
}

