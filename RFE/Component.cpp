#include "pch.h"
#include "Component.h"

#include "Entity.h"

std::shared_ptr<rfe::Entity> rfe::Component::GetEntity() const
{
	return entity.lock();
}

bool rfe::Component::GetEnabled() const
{
	return enabled;
}

void rfe::Component::SetEnabled(bool value)
{
	enabled = value;

	if (enabled && !started)
	{
		started = true;
		OnStart();
	}

	if (started)
	{
		if (enabled)
		{
			OnEnable();
		}
		else
		{
			OnDisable();
		}
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
	OnStart();
	OnEnable();

	started = true;
}

void rfe::Component::Update()
{
	if (!enabled)
	{
		return;
	}

	OnUpdate();
}

void rfe::Component::Unload()
{
	if (enabled)
	{
		enabled = false;
		OnDisable();
	}

	OnUnload();
}