#include "pch.h"
#include "Component.h"

#include "Entity.h"

rfe::Entity* rfe::Component::GetEntity() const
{
    return entity;
}

bool rfe::Component::GetEnabled() const
{
    return enabled;
}

void rfe::Component::SetEnabled(bool value)
{
    enabled = value;

    Start();

    if (enabled)
    {
        OnEnable();
    }
    else
    {
        OnDisable();
    }
}

void rfe::Component::Load()
{
    OnLoad();
}

void rfe::Component::Start()
{
    if (started || !enabled)
    {
        return;
    }

    started = true;

    OnStart();
}

void rfe::Component::Update()
{
    if (!enabled)
    {
        return;
    }

    OnUpdate();
}