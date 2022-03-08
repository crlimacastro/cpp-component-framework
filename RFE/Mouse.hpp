#pragma once

namespace rfe
{
	template<typename T>
	struct Vector2D;
}

namespace rfe::Mouse
{
	RFE_API enum class Button
	{
		Left = 0,       // Mouse button left
		Right = 1,       // Mouse button right
		Middle = 2,       // Mouse button middle (pressed wheel)
		Side = 3,       // Mouse button side (advanced mouse device)
		Extra = 4,       // Mouse button extra (advanced mouse device)
		Forward = 5,       // Mouse button fordward (advanced mouse device)
		Back = 6,       // Mouse button back (advanced mouse device)
	};

	RFE_API bool ButtonPressed(Button button);
	RFE_API bool ButtonDown(Button button);
	RFE_API bool ButtonReleased(Button button);
	RFE_API bool ButtonUp(Button button);
	RFE_API Vector2D<float> GetPosition();
	// Get mouse delta between frames
	RFE_API Vector2D<float> GetPositionDelta();
	RFE_API void SetPosition(int x, int y);
	RFE_API void SetOffset(int x, int y);
	RFE_API void SetScale(float x, float y);
	RFE_API float GetWheel();
};

