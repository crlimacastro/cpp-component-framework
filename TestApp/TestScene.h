#pragma once

class TestScene : public rfe::Scene
{
protected:
	void OnLoad() override
	{
		auto camera = rfe::CameraPrefab().Create();
		AddEntity(camera);
		AddEntity(FPSCounterPrefab().Create());

		auto cube = rfe::Entity::Create();
		cube->AddComponent<rfe::Transform>();
		auto drawer = cube->AddComponent<CubeDrawer>();
		drawer->camera = camera->GetComponent<rfe::CameraComponent>();
		cube->AddComponent<KeyboardController>();
		AddEntity(cube);

		auto callbacksTester = rfe::Entity::Create();
		callbacksTester->SetName("Callbacks Tester");
		callbacksTester->AddComponent<CallbacksTester>()->SetEnabled(false);
		callbacksTester->AddComponent<CallbacksTesterToggler>();
		AddEntity(callbacksTester);
	}
};