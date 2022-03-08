#include "pch.h"
#include "Mouse.hpp"

#include "Vector2D.hpp"

bool rfe::Mouse::ButtonPressed(Button button)
{
	return IsMouseButtonPressed((int)button);
}

bool rfe::Mouse::ButtonDown(Button button)
{
	return IsMouseButtonDown((int)button);
}

bool rfe::Mouse::ButtonReleased(Button button)
{
	return IsMouseButtonReleased((int)button);
}

bool rfe::Mouse::ButtonUp(Button button)
{
	return IsMouseButtonUp((int)button);
}

rfe::Vector2D<float> rfe::Mouse::GetPosition()
{
	return Vector2D<float>::From(GetMousePosition());
}

rfe::Vector2D<float> rfe::Mouse::GetPositionDelta()
{
	return Vector2D<float>::From(GetMouseDelta());
}

void rfe::Mouse::SetPosition(int x, int y)
{
	SetMousePosition(x, y);
}

void rfe::Mouse::SetOffset(int x, int y)
{
	SetMouseOffset(x, y);
}

void rfe::Mouse::SetScale(float x, float y)
{
	SetMouseScale(x, y);
}

float rfe::Mouse::GetWheel()
{
	return GetMouseWheelMove();
}
