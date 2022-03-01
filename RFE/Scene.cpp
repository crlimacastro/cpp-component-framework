#include "pch.h"
#include "Scene.h"

void rfe::Scene::AddEntity(const Entity& entity)
{
	entities.insert(std::make_shared<Entity>(entity));
}

void rfe::Scene::RemoveEntity(const Entity& entity)
{
	std::erase_if(entities, [&entity](auto e) {
		if (e.get() == &entity)
		{
			e->SetParent(nullptr);
			return true;
		}

		return false;
		});
}

void rfe::Scene::ClearEntities()
{
	entities.clear();
}

void rfe::Scene::Update()
{
	for (auto& entity : entities)
	{
		entity->Update();
	}
}

void rfe::Scene::Load()
{
	OnLoad();

	for (auto& entity : entities)
	{
		entity->Load();
	}

	for (auto& entity : entities)
	{
		entity->Start();
	}
}