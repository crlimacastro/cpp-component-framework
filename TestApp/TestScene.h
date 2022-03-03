#pragma once

class TestScene : public rfe::Scene
{
protected:
	void OnLoad() override
	{
		auto cameraPrefab = rfe::CameraPrefab();
		auto cameraEntity = cameraPrefab.Create();
		AddEntity(cameraEntity);

		auto fpsDrawerEntity = rfe::Entity::Create();
		fpsDrawerEntity->SetName("FPS Drawer");
		auto fpsDrawerTransform = fpsDrawerEntity->AddComponent<rfe::Transform>();
		fpsDrawerTransform->position = rfe::Vector3f(20.0f, 20.0f, 0.0f);
		auto fpsDrawer = fpsDrawerEntity->AddComponent<FPSDrawer>();
		fpsDrawer->SetEnabled(false);
		auto fpsToggler = fpsDrawerEntity->AddComponent<FPSToggler>();
		AddEntity(fpsDrawerEntity);

		auto callbacksTester = rfe::Entity::Create();
		callbacksTester->SetName("Callbacks Tester");
		callbacksTester->AddComponent<CallbacksTester>()->SetEnabled(false);
		callbacksTester->AddComponent<CallbacksTesterToggler>();
		AddEntity(callbacksTester);
	}
};