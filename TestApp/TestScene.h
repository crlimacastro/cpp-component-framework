#pragma once

#include "RFE.h"

class TestScene : public rfe::Scene
{
public:
	TestScene() = default;

protected:
	void OnLoad() override
	{
		auto cameraEntity = std::make_shared<rfe::Entity>();
		//cameraEntity->AddComponent<rfe::Transform>();
		cameraEntity->AddComponent<rfe::Camera>();
		AddEntity(*cameraEntity);
	}
};