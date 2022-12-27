#include "pch.h"
#include "CameraPrefab.h"

#include "Entity.h"
#include "Transform.h"
#include "CameraComponent.h"

std::shared_ptr<rfe::Entity> rfe::CameraPrefab::Create() const
{
	auto entity = Entity::Create();
	entity->SetName("Camera");
	auto transform = entity->AddComponent<Transform>();
	transform->position = { 0, 0, 10 };
	auto camera = entity->AddComponent<CameraComponent>();
	return entity;
}
