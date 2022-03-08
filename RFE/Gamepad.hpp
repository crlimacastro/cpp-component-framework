#pragma once

namespace rfe
{
	// Private constructor. Get with public static Gamepad::Get(int gamepad = 0).
	// Will return nullptr if not a valid gamepad number.
	class RFE_API Gamepad
	{
	public:
		enum class Button
		{
			DpadUp,        // Gamepad left DPAD up button
			DpadRight,     // Gamepad left DPAD right button
			DpadDown,      // Gamepad left DPAD down button
			DpadLeft,      // Gamepad left DPAD left button
			Top,       // Gamepad right button up (i.e. PS3: Triangle, Xbox: Y)
			Right,    // Gamepad right button right (i.e. PS3: Square, Xbox: X)
			Bottom,     // Gamepad right button down (i.e. PS3: Cross, Xbox: A)
			Left,     // Gamepad right button left (i.e. PS3: Circle, Xbox: B)
			TriggerFrontLeft,      // Gamepad top/back trigger left (first), it could be a trailing button
			TriggerBackLeft,      // Gamepad top/back trigger left (second), it could be a trailing button
			TriggerFrontRight,     // Gamepad top/back trigger right (one), it could be a trailing button
			TriggerBackRight,     // Gamepad top/back trigger right (second), it could be a trailing button
			CenterLeft,         // Gamepad center buttons, left one (i.e. PS3: Select)
			CenterMiddle,              // Gamepad center buttons, middle one (i.e. PS3: PS, Xbox: XBOX)
			CenterRight,        // Gamepad center buttons, right one (i.e. PS3: Start)
			StickLeft,          // Gamepad joystick pressed button left
			StickRight,          // Gamepad joystick pressed button right
		};
		enum class Axis
		{
			LeftX = 0,     // Gamepad left stick X axis
			LeftY = 1,     // Gamepad left stick Y axis
			RightX = 2,     // Gamepad right stick X axis
			RightY = 3,     // Gamepad right stick Y axis
			TriggerLeftPressure = 4,     // Gamepad back trigger left, pressure level: [1..-1]
			TriggerRightPressure = 5      // Gamepad back trigger right, pressure level: [1..-1]
		};
	public:
		static std::shared_ptr<Gamepad> Get(int gamepad = 0);
		std::string GetName() const;
		bool ButtonPressed(Button button) const;
		bool ButtonDown(Button button) const;
		bool ButtonReleased(Button button) const;
		bool ButtonUp(Button button) const;
		Button GetLastButtonPressed() const;
		int GetAxisCount() const;
		float GetAxis(Axis axis) const;

	private:
		Gamepad(int gamepad = 0) : gamepad(gamepad) {}
		int gamepad;
	};

	namespace Gamepads
	{
		RFE_API std::shared_ptr<std::vector<std::shared_ptr<Gamepad>>> GetGamepads();
	}
}