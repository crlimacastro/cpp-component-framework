#include "pch.h"
#include "CameraPrefab.h"

#include "Entity.h"
#include "Prefab.h"
#include "Transform.h"
#include "Camera.h"

std::shared_ptr<rfe::Entity> rfe::CameraPrefab::Create() const
{
	auto entity = std::make_shared<Entity>();
	entity->AddComponent<rfe::Transform>();
	entity->AddComponent<rfe::Camera>();
	return entity;
}
