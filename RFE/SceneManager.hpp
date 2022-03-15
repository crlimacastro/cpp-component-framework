#pragma once

#include "Scene.hpp"

namespace rfe
{
	class RFE_API SceneManager
	{
	public:
		std::shared_ptr<Scene> GetCurrentScene();

		template <typename T>
		void LoadScene()
		{
			if (currentScene)
			{
				currentScene->Unload();
			}
			currentScene = std::make_shared<T>();
			currentScene->Load();
		}

		void UnloadScene();

	private:
		std::shared_ptr<Scene> currentScene = nullptr;
	};
}

