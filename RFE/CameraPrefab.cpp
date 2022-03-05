#include "pch.h"
#include "CameraPrefab.hpp"

#include "Entity.hpp"
#include "Transform.hpp"
#include "CameraComponent.hpp"

std::shared_ptr<rfe::Entity> rfe::CameraPrefab::Create() const
{
	auto entity = Entity::Create();
	entity->SetName("Camera");
	auto transform = entity->AddComponent<Transform>();
	transform->position = { 0, 0, -10 };
	auto camera = entity->AddComponent<CameraComponent>();
	camera->transform = transform;
	return entity;
}
