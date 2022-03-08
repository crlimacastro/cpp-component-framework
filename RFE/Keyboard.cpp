#include "pch.h"
#include "Keyboard.hpp"

bool rfe::Keyboard::KeyPressed(Key key)
{
	return IsKeyPressed((int)key);
}

bool rfe::Keyboard::KeyDown(Key key)
{
	return IsKeyDown((int)key);
}

bool rfe::Keyboard::KeyReleased(Key key)
{
	return IsKeyReleased((int)key);
}

bool rfe::Keyboard::KeyUp(Key key)
{
	return IsKeyUp((int)key);
}