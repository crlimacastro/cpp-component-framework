#pragma once

#include "RFE.h"

#include "Components.h"
#include "Prefabs.h"
#include "Scenes.h"

class TestApp : public rfe::Application
{
protected:
    void OnStart() override
    {
        Settings.SetForceStopKey(KEY_ESCAPE);
		Settings.TargetFPS(120);
        SceneManager.LoadScene<TestScene>();
    }

    rfe::Vector3D<float> cubePosition = {0, 0, 0};
    float speed = 10;

    void OnUpdate() override
    {
		auto newPosition = cubePosition;

		if (IsKeyDown(KEY_W))
		{
			newPosition.y += speed * rfe::Time::GetDeltaTime();
		}
		if (IsKeyDown(KEY_A))
		{
			newPosition.x -= speed * rfe::Time::GetDeltaTime();
		}
		if (IsKeyDown(KEY_S))
		{
			newPosition.y -= speed * rfe::Time::GetDeltaTime();
		}
		if (IsKeyDown(KEY_D))
		{
			newPosition.x += speed * rfe::Time::GetDeltaTime();
		}

		cubePosition = newPosition;
        DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
        DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
        DrawGrid(10, 1.0f);
    }
};