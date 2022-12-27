#pragma once
#include "Scene.h"

namespace rfe
{
	template <typename T>
	concept TScene = std::is_base_of_v<Scene, T>;

	class RFE_API SceneManager
	{
	public:
		static ref<Scene> GetCurrentScene();

		template <TScene T>
		static void LoadScene()
		{
			if (currentScene)
			{
				currentScene->Unload();
			}

			currentScene = std::make_shared<T>();
			currentScene->Load();
		}

		static void UnloadScene();

	private:
		inline static rfe::ref<rfe::Scene> currentScene = nullptr;

		SceneManager() = delete;
	};
}

