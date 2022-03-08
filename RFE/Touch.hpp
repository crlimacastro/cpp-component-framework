#pragma once

namespace rfe
{
	template<typename T>
	struct Vector2D;

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
		// Gets all enabled gestures
		std::unordered_set<Gesture> GetEnabledGestures();
		bool IsGestureEnabled(Gesture gesture);
		void SetGestureEnabled(Gesture gesture, bool value);

		bool IsDetected(Gesture gesture);
		Gesture GetLastGesture();
		float GetHoldDuration();
		Vector2D<float> GetDragVector();
		float GetDragAngle();
		Vector2D<float> GetPinchVector();
		float GetPinchAngle();
	}

	class RFE_API Touch
	{
	public:
		static std::shared_ptr<Touch> Get(int touch = 0);
		Vector2D<float> GetPosition() const;
	private:
		Touch(int touch = 0) : touch(touch) {}
		int touch;
	};
};

namespace rfe::Touches
{
	RFE_API std::shared_ptr<std::vector<std::shared_ptr<Touch>>> GetTouches();
}