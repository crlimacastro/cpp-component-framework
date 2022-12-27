#include "pch.h"
#include "Scene.h"

void rfe::Scene::AddEntity(rfe::ref<Entity> entity)
{
	entities.emplace(entity);
	if (loaded)
	{
		entity->Load();
		entity->Start();
	}
}

void rfe::Scene::RemoveEntity(rfe::ref<Entity> entity)
{
	if (entities.contains(entity))
	{
		entities.erase(entity);
		entity->Unload();
	}
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

void rfe::Scene::Draw3D()
{
	for (auto& entity : entities)
	{
		entity->Draw3D();
	}
}

void rfe::Scene::Draw2D()
{
	for (auto& entity : entities)
	{
		entity->Draw2D();
	}
}

void rfe::Scene::DrawScreen()
{
	for (auto& entity : entities)
	{
		entity->DrawScreen();
	}
}

void rfe::Scene::PostDrawUpdate()
{
	for (auto& entity : entities)
	{
		entity->PostDrawUpdate();
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

	loaded = true;
}

void rfe::Scene::Unload()
{
	for (auto& entity : entities)
	{
		entity->Unload();
	}

	OnUnload();
}
