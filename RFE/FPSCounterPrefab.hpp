#pragma once

#include "Prefab.hpp"

namespace rfe
{
	class RFE_API FPSCounterPrefab : public Prefab
	{
	public:
		std::shared_ptr<rfe::Entity> Create() const;
	};
}