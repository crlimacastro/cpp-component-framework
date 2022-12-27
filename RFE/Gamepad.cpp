#include "pch.h"
#include "Gamepad.h"

rfe::ref<rfe::Gamepad> rfe::Gamepad::Get(int gamepad)
{
	if (!IsGamepadAvailable(gamepad))
	{
		return nullptr;
	}

	return ref<Gamepad>(new Gamepad(gamepad));
}

std::string rfe::Gamepad::GetName() const
{
	return GetGamepadName(gamepad);
}

bool rfe::Gamepad::ButtonPressed(Button button) const
{
	return IsGamepadButtonPressed(gamepad, (int)button);
}

bool rfe::Gamepad::ButtonDown(Button button) const
{
	return IsGamepadButtonDown(gamepad, (int)button);
}

bool rfe::Gamepad::ButtonReleased(Button button) const
{
	return IsGamepadButtonReleased(gamepad, (int)button);
}

bool rfe::Gamepad::ButtonUp(Button button) const
{
	return IsGamepadButtonUp(gamepad, (int)button);
}

rfe::Gamepad::Button rfe::Gamepad::GetLastButtonPressed() const
{
	return (Button)GetGamepadButtonPressed();
}

int rfe::Gamepad::GetAxisCount() const
{
	return GetGamepadAxisCount(gamepad);
}

float rfe::Gamepad::GetAxis(Axis axis) const
{
	return GetGamepadAxisMovement(gamepad, (int)axis);
}

std::vector<rfe::ref<rfe::Gamepad>> rfe::Gamepads::GetGamepads()
{
	auto gamepads = std::vector<ref<Gamepad>>();
	int gamepad = 0;
	while (IsGamepadAvailable(gamepad))
	{
		gamepads.push_back(ref<Gamepad>(Gamepad::Get(gamepad)));
		gamepad++;
	}
	return gamepads;
}
