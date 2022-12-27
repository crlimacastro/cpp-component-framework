#pragma once

#include "Prefab.h"

namespace rfe
{
	class RFE_API FPSCounterPrefab : public Prefab
	{
	public:
		std::shared_ptr<rfe::Entity> Create() const;
	};
}