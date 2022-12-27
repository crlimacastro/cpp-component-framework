#pragma once

class Tester : public rfe::Component
{
protected:
	void OnUpdate() override
	{
		rfe::v3f direction;

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

		if (IsKeyPressed(KEY_SPACE))
		{

		}

		if (IsKeyPressed(KEY_TAB))
		{

		}
	}

	void OnDraw3D() override
	{
		DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
		DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
		DrawGrid(10, 1.0f);
	}
private:
	rfe::v3f cubePosition = { 0, 0, 0 };
	float speed = 10;
};