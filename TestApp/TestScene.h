#pragma once

class TestScene : public rfe::Scene
{
protected:
	void OnLoad() override
	{
		auto camera = rfe::CameraPrefab().Create();
		auto transform = camera->GetComponent<rfe::Transform>();
		transform->position = { -10, 10, 10 };
		AddEntity(camera);

		AddEntity(FPSCounterPrefab().Create());
	}
};