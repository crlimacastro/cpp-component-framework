#include "pch.h"
#include "Entity.h"

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

void rfe::Entity::SetParent(Entity *entity)
{
    parent = entity;
    entity->children.insert(this);
}

void rfe::Entity::AddChild(Entity& entity)
{
    children.insert(&entity);
    entity.parent = this;
}

void rfe::Entity::RemoveChild(Entity& entity)
{
    if (children.contains(&entity))
    {
        entity.parent = nullptr;
        children.erase(&entity);
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

void rfe::Entity::Destroy(const Entity& entity)
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