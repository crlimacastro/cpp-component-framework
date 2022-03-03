#include "pch.h"
#include "CameraPrefab.h"

#include "Entity.h"
#include "Prefab.h"
#include "Transform.h"
#include "CameraComponent.h"

std::shared_ptr<rfe::Entity> rfe::CameraPrefab::Create() const
{
	auto entity = Entity::Create();
	entity->SetName("Camera");
	entity->AddComponent<rfe::Transform>();
	entity->AddComponent<rfe::CameraComponent>();
	return entity;
}
