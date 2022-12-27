#include "pch.h"
#include "Entity.h"

#include "Component.h"
#include "SceneManager.h"
#include "Application.h"

rfe::ref<rfe::Entity> rfe::Entity::Create()
{
	return std::make_shared<Entity>();
}

void rfe::Entity::Destroy(rfe::ref<Entity> entity)
{
	SceneManager::GetCurrentScene()->RemoveEntity(entity);
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
		for (auto& componentType : components)
		{
			for (auto& component : *componentType.second)
			{
				component->OnEnable();
			}
		}
	}
	else
	{
		for (auto& componentType : components)
		{
			for (auto& component : *componentType.second)
			{
				component->OnEnable();
			}
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

void rfe::Entity::Load()
{
	for (auto& componentType : components)
	{
		for (auto& component : *componentType.second)
		{
			component->Load();
		}
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

	for (auto& componentType : components)
	{
		for (auto& component : *componentType.second)
		{
			component->Start();
		}
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

	for (auto& componentType : components)
	{
		for (auto& component : *componentType.second)
		{
			component->Update();
		}
	}

	for (auto& child : children)
	{
		child->Update();
	}
}

void rfe::Entity::Draw3D()
{
	if (!enabled)
	{
		return;
	}

	for (auto& componentType : components)
	{
		for (auto& component : *componentType.second)
		{
			component->Draw3D();
		}
	}

	for (auto& child : children)
	{
		child->Draw3D();
	}
}

void rfe::Entity::Draw2D()
{
	if (!enabled)
	{
		return;
	}

	for (auto& componentType : components)
	{
		for (auto& component : *componentType.second)
		{
			component->Draw2D();
		}
	}

	for (auto& child : children)
	{
		child->Draw2D();
	}
}

void rfe::Entity::DrawScreen()
{
	if (!enabled)
	{
		return;
	}

	for (auto& componentType : components)
	{
		for (auto& component : *componentType.second)
		{
			component->DrawScreen();
		}
	}

	for (auto& child : children)
	{
		child->DrawScreen();
	}
}

void rfe::Entity::PostDrawUpdate()
{
	if (!enabled)
	{
		return;
	}

	for (auto& componentType : components)
	{
		for (auto& component : *componentType.second)
		{
			component->PostDrawUpdate();
		}
	}

	for (auto& child : children)
	{
		child->PostDrawUpdate();
	}
}

void rfe::Entity::Unload()
{
	for (auto& componentType : components)
	{
		for (auto& component : *componentType.second)
		{
			component->Unload();
		}
	}

	for (auto& child : children)
	{
		child->Unload();
	}
}