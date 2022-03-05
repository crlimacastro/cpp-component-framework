#pragma once

class CallbacksTesterPrefab : public rfe::Prefab
{
public:
	std::shared_ptr<rfe::Entity> Create() const
	{
		auto entity = rfe::Entity::Create();
		entity->SetName("Callbacks Tester");
		auto tester = entity->AddComponent<CallbacksTester>();
		tester->SetEnabled(false);
		auto toggler = entity->AddComponent<CallbacksTesterToggler>();
		toggler->callbacksTester = tester;
		return entity;
	}
};