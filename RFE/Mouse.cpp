#include "pch.h"
#include "Mouse.h"

#include "v2f.h"

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

rfe::v2f rfe::Mouse::GetPosition()
{
	return v2f(GetMousePosition());
}

rfe::v2f rfe::Mouse::GetPositionDelta()
{
	return v2f(GetMouseDelta());
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