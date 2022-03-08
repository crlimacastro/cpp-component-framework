#include "pch.h"
#include "Entity.hpp"

#include "Component.hpp"
#include "SceneManager.hpp"
#include "Application.hpp"

std::shared_ptr<rfe::Entity> rfe::Entity::Create()
{
	return std::shared_ptr<Entity>(new Entity());
}

bool rfe::Entity::GetEnabled() const
{
	return enabled;
}

void rfe::Entity::SetEnabled(bool value)
{
	enabled = value;

	Start();

	if (enabled)
	{
		for (auto& component : components)
		{
			component->OnEnable();
		}
	}
	else
	{
		for (auto& component : components)
		{
			component->OnDisable();
		}
	}
}

std::string rfe::Entity::GetName() const
{
	return name;
}

void rfe::Entity::SetName(const std::string value)
{
	name = value;
}

std::shared_ptr<rfe::Entity> rfe::Entity::GetParent() const
{
	return parent.lock();
}

void rfe::Entity::SetParent(std::shared_ptr<Entity> entity)
{
	if (entity == shared_from_this())
	{
		return;
	}

	if (auto p = parent.lock())
	{
		for (auto& child : p->children)
		{
			if (child == shared_from_this())
			{
				p->children.erase(child);
				break;
			}
		}
	}

	parent = entity;

	if (entity)
	{
		entity->children.emplace(shared_from_this());
	}
}

void rfe::Entity::AddChild(std::shared_ptr<Entity> entity)
{
	children.emplace(entity);

	if (auto p = entity->parent.lock()) {
		p->children.erase(entity);
	}

	entity->parent = shared_from_this();
}

void rfe::Entity::RemoveChild(std::shared_ptr<Entity> entity)
{
	if (children.contains(entity))
	{
		entity->parent.reset();
		children.erase(entity);
	}
}

void rfe::Entity::ClearChildren()
{
	for (auto& child : children)
	{
		child->parent.reset();
	}

	children.clear();
}

void rfe::Entity::Destroy(std::shared_ptr<Entity> entity)
{
	Application::GetActive()->sceneManager.GetCurrentScene()->RemoveEntity(entity);
}

void rfe::Entity::Load()
{
	for (auto& component : components)
	{
		component->Load();
	}

	for (auto& child : children)
	{
		child->Load();
	}
}

void rfe::Entity::Start()
{
	if (!enabled)
	{
		return;
	}

	for (auto& component : components)
	{
		component->Start();
	}

	for (auto& child : children)
	{
		child->Start();
	}
}

void rfe::Entity::Update()
{
	if (!enabled)
	{
		return;
	}

	for (auto& component : components)
	{
		component->Update();
	}

	for (auto& child : children)
	{
		child->Update();
	}
}

void rfe::Entity::Unload()
{
	for (auto& component : components)
	{
		component->Unload();
	}

	for (auto& child : children)
	{
		child->Unload();
	}
}
