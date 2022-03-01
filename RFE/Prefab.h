#pragma once

#include "Entity.h"

namespace rfe
{
	// Inherit to create your own Prefabs
	// Override public Create() to define the Entity
	class RFE_API Prefab
	{
	public:
		virtual std::shared_ptr<Entity> Create() const = 0;
	};
}