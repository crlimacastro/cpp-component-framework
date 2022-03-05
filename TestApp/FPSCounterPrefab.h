#pragma once

class FPSCounterPrefab : public rfe::Prefab
{
public:
	std::shared_ptr<rfe::Entity> Create() const
	{
		auto entity = rfe::Entity::Create();
		entity->SetName("FPS Counter");
		auto transform = entity->AddComponent<rfe::Transform>();
		transform->position = { 20, 20, 0 };
		auto drawer = entity->AddComponent<FPSDrawer>();
		drawer->transform = transform;
		drawer->SetEnabled(false);
		auto toggler = entity->AddComponent<FPSToggler>();
		toggler->fpsDrawer = drawer;
		return entity;
	}
};