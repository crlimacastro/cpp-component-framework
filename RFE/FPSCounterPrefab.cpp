#include "pch.h"
#include "FPSCounterPrefab.hpp"

#include "Entity.hpp"
#include "Transform.hpp"
#include "FPSDrawer.hpp"
#include "FPSToggler.hpp"

std::shared_ptr<rfe::Entity> rfe::FPSCounterPrefab::Create() const
{
	auto entity = rfe::Entity::Create();
	entity->SetName("FPS Counter");
	auto transform = entity->AddComponent<rfe::Transform>();
	transform->position = { 20, 20, 0 };
	auto drawer = entity->AddComponent<FPSDrawer>();
	drawer->SetEnabled(false);
	auto toggler = entity->AddComponent<FPSToggler>();
	return entity;
}