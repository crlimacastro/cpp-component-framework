#include "pch.h"
#include "Component.hpp"

#include "Entity.hpp"

std::shared_ptr<rfe::Entity> rfe::Component::GetEntity()
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

void rfe::Component::Draw3D()
{
	if (!enabled)
	{
		return;
	}

	OnDraw3D();

#ifdef _DEBUG
	OnDraw3DDebug();
#endif
}

void rfe::Component::Draw2D()
{
	if (!enabled)
	{
		return;
	}

	OnDraw2D();

#ifdef _DEBUG
	OnDraw2DDebug();
#endif
}

void rfe::Component::DrawScreen()
{
	if (!enabled)
	{
		return;
	}

	OnDrawScreen();

#ifdef _DEBUG
	OnDrawScreenDebug();
#endif
}

void rfe::Component::PostDrawUpdate()
{
	if (!enabled)
	{
		return;
	}

	OnPostDrawUpdate();
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