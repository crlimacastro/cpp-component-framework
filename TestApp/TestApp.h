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
        GetSettings()->TargetFPS(60);
        rfe::SceneManager::LoadScene<TestScene>();
    }

    void OnUpdate() override
    {

    }
};