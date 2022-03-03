#pragma once

class TestScene : public rfe::Scene
{
protected:
	void OnLoad() override
	{
		AddEntity(rfe::CameraPrefab().Create());
		AddEntity(FPSCounterPrefab().Create());

		auto callbacksTester = rfe::Entity::Create();
		callbacksTester->SetName("Callbacks Tester");
		callbacksTester->AddComponent<CallbacksTester>()->SetEnabled(false);
		callbacksTester->AddComponent<CallbacksTesterToggler>();
		AddEntity(callbacksTester);
	}
};