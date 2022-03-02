#include "pch.h"
#include "Entity.h"

#include "Component.h"
#include "SceneManager.h"

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

void rfe::Entity::SetParent(std::shared_ptr<Entity> entity)
{
	if (entity.get() == this)
	{
		return;
	}

	if (parent)
	{
		for (auto& c : parent->children)
		{
			if (c.get() == this)
			{
				parent->children.erase(c);
				break;
			}
		}
	}

	parent = entity;

	if (entity)
	{
		entity->children.emplace(this);
	}
}

void rfe::Entity::AddChild(std::shared_ptr<Entity> entity)
{
	children.emplace(entity);

	if (entity->parent) {
		entity->parent->children.erase(entity);
	}

	entity->parent = std::shared_ptr<Entity>(this);
}

void rfe::Entity::RemoveChild(std::shared_ptr<Entity> entity)
{
	if (children.contains(entity))
	{
		entity->parent = nullptr;
		children.erase(entity);
	}
}

void rfe::Entity::ClearChildren()
{
	for (auto& child : children)
	{
		child->parent = nullptr;
	}

	children.clear();
}

void rfe::Entity::Destroy(std::shared_ptr<Entity> entity)
{
	SceneManager::GetCurrentScene()->RemoveEntity(entity);
}

void rfe::Entity::Load()
{
	for (auto& component : components)
	{
		component->Load();
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
}