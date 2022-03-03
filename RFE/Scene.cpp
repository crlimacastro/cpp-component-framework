#include "pch.h"
#include "Scene.h"

void rfe::Scene::AddEntity(std::shared_ptr<Entity> entity)
{
	entities.emplace(entity);
}

void rfe::Scene::RemoveEntity(std::shared_ptr<Entity> entity)
{
	entities.erase(entity);
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

	OnStart();

	for (auto& entity : entities)
	{
		entity->Start();
	}
}

void rfe::Scene::Unload()
{
	for (auto& entity : entities)
	{
		entity->Unload();
	}

	OnUnload();
}
