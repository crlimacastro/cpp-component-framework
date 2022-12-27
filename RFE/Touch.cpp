#include "pch.h"
#include "Touch.h"

#include "v2f.h"

rfe::ref<rfe::Touch> rfe::Touch::Get(int touch)
{
	if (touch < 0 || touch >= GetTouchPointCount())
	{
		return nullptr;
	}

	return ref<Touch>(new Touch(touch));
}

rfe::v2f rfe::Touch::GetPosition() const
{
	return v2f(GetTouchPosition(touch));
}

std::vector<rfe::ref<rfe::Touch>> rfe::Touches::GetTouches()
{
	auto touches = std::vector<ref<Touch>>();
	int touchCount = GetTouchPointCount();
	for (int i = 0; i < touchCount; i++)
	{
		touches.push_back(Touch::Get(i));
	}
	return touches;
}

void rfe::Gestures::SetEnabled(unsigned int flags)
{
	SetGesturesEnabled(flags);
}

bool rfe::Gestures::IsDetected(Gesture gesture)
{
	return IsGestureDetected((int)gesture);
}

rfe::Gesture rfe::Gestures::GetLastGesture()
{
	return (Gesture)GetGestureDetected();
}

float rfe::Gestures::GetHoldDuration()
{
	return GetGestureHoldDuration();
}

rfe::v2f rfe::Gestures::GetDragVector()
{
	return v2f(GetGestureDragVector());
}

float rfe::Gestures::GetDragAngle()
{
	return GetGestureDragAngle();
}

rfe::v2f rfe::Gestures::GetPinchVector()
{
	return v2f(GetGesturePinchVector());
}

float rfe::Gestures::GetPinchAngle()
{
	return GetGesturePinchAngle();
}
