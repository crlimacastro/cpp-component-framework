#pragma once

#include "Camera.h"

namespace rfe
{
	class RFE_API CameraPrefab : public Prefab
	{
	public:
		std::shared_ptr<Entity> Create() const {
			std::shared_ptr<Entity> entity = std::make_shared<Entity>();
			entity->AddComponent<Transform>();
			entity->AddComponent<Camera>();
			return entity;
		}
	};
}