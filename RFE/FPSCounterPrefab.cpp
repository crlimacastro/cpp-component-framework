#include "pch.h"
#include "FPSCounterPrefab.h"

#include "Entity.h"
#include "Transform.h"
#include "FPSDrawer.h"
#include "FPSToggler.h"

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