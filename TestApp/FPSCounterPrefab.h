#pragma once

class FPSCounterPrefab : public rfe::Prefab
{
public:
	std::shared_ptr<rfe::Entity> Create() const
	{
		auto entity = rfe::Entity::Create();
		entity->SetName("FPS Counter");
		auto transform = entity->AddComponent<rfe::Transform>();
		transform->position = rfe::Vector3f(20.0f, 20.0f, 0.0f);
		auto drawer = entity->AddComponent<FPSDrawer>();
		drawer->SetEnabled(false);
		entity->AddComponent<FPSToggler>();
		return entity;
	}
};