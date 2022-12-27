#pragma once

#include "Entity.h"

namespace rfe
{
	// Inherit to create your own Prefabs
	// Overrides:
	// public Create() [Required] -> Define how entity is created, attach Components, and return the entity
	class RFE_API Prefab
	{
	public:
		virtual std::shared_ptr<Entity> Create() const = 0;
	};
}