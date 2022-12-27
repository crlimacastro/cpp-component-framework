#pragma once

namespace rfe
{
	struct v2f;

	class RFE_API Touch
	{
	public:
		static ref<Touch> Get(int touch = 0);
		v2f GetPosition() const;
	private:
		Touch(int touch = 0) : touch(touch) {}
		int touch;
	};

	namespace Touches
	{
		RFE_API std::vector<ref<Touch>> GetTouches();
	}

	enum class Gesture
	{
		None = 0,        // No gesture
		Tap = 1,        // Tap gesture
		DoubleTap = 2,        // Double tap gesture
		Hold = 4,        // Hold gesture
		Drag = 8,        // Drag gesture
		SwipeRight = 16,       // Swipe right gesture
		SwipeLeft = 32,       // Swipe left gesture
		SwipeUp = 64,       // Swipe up gesture
		SwipeDown = 128,      // Swipe down gesture
		PinchIn = 256,      // Pinch in gesture
		PinchOut = 512       // Pinch out gesture
	};

	namespace Gestures
	{
		void SetEnabled(unsigned int flags);
		bool IsDetected(Gesture gesture);

		Gesture GetLastGesture();

		float GetHoldDuration();
		v2f GetDragVector();
		float GetDragAngle();
		v2f GetPinchVector();
		float GetPinchAngle();
	}
};