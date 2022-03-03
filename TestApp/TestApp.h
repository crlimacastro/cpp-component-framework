#pragma once

#include "RFE.h"

#include "Components.h"
#include "Prefabs.h"
#include "Scenes.h"

class TestApp : public rfe::Application
{
public:
    TestApp() = default;
protected:
    void OnStart() override
    {
        GetSettings()->SetForceStopKey(KEY_ESCAPE);
        rfe::SceneManager::LoadScene<TestScene>();
    }
};