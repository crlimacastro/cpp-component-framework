#pragma once

#include "RFE.h"
using namespace rfe;

#include "Components.h"
#include "Prefabs.h"
#include "Scenes.h"

class TestApp : public rfe::Application
{
protected:
	void OnStart() override
	{
		settings.SetForceStopKey(KEY_ESCAPE);
		SceneManager::LoadScene<TestScene>();
	}
};