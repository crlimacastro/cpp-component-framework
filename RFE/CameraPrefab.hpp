#pragma once

#include "Prefab.hpp"

namespace rfe
{
	class RFE_API CameraPrefab : public Prefab
	{
	public:
		std::shared_ptr<Entity> Create() const;
	};
}