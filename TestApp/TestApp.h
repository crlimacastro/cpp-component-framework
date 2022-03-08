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
		settings.SetForceStopKey(KEY_ESCAPE);
		sceneManager.LoadScene<TestScene>();
	}

	rfe::Vector3D<float> cubePosition = { 0, 0, 0 };
	float speed = 10;

	void OnUpdate() override
	{
		rfe::Vector3D<float> direction;

		if (IsKeyDown(KEY_W))
		{
			direction.y += 1;
		}
		if (IsKeyDown(KEY_A))
		{
			direction.x -= 1;
		}
		if (IsKeyDown(KEY_S))
		{
			direction.y -= 1;
		}
		if (IsKeyDown(KEY_D))
		{
			direction.x += 1;
		}

		direction.Normalize();

		cubePosition += direction * speed * GetFrameTime();

		fnBuffer3D.Push([&]() {
			DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
			DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
			DrawGrid(10, 1.0f);
			});

		if (IsKeyPressed(KEY_SPACE))
		{

		}

		if (IsKeyPressed(KEY_TAB))
		{

		}
	}
};