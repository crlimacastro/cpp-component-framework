#pragma once

#include "RFE.h"
#include "TestScene.h"

class TestApp : public rfe::Application
{
public:
    TestApp() = default;
protected:
    void OnStart() override
    {
        SetStopKey(KEY_ESCAPE);
        rfe::SceneManager::LoadScene<TestScene>();
    }
};