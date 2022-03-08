#include "pch.h"
#include "Touch.hpp"

#include "Vector2D.hpp"

std::shared_ptr<rfe::Touch> rfe::Touch::Get(int touch)
{
	if (touch < 0 || touch >= GetTouchPointCount())
	{
		return nullptr;
	}

	return std::shared_ptr<Touch>(new Touch(touch));
}

rfe::Vector2D<float> rfe::Touch::GetPosition() const
{
	return Vector2D<float>::From(GetTouchPosition(touch));
}

std::shared_ptr<std::vector<std::shared_ptr<rfe::Touch>>> rfe::Touches::GetTouches()
{
	auto touches = std::make_shared<std::vector<std::shared_ptr<Touch>>>();
	int touchCount = GetTouchPointCount();
	for (int i = 0; i < touchCount; i++)
	{
		touches->push_back(Touch::Get(i));
	}
	return touches;
}

static std::unordered_set<rfe::Gesture> enabledGestures;

std::unordered_set<rfe::Gesture> rfe::Gestures::GetEnabledGestures()
{
	return enabledGestures;
}

bool rfe::Gestures::IsGestureEnabled(Gesture gesture)
{
	return enabledGestures.find(gesture) != enabledGestures.end();
}

void rfe::Gestures::SetGestureEnabled(Gesture gesture, bool value)
{
	if (value)
	{
		enabledGestures.insert(gesture);
	}
	else
	{
		enabledGestures.erase(gesture);
	}
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

rfe::Vector2D<float> rfe::Gestures::GetDragVector()
{
	return Vector2D<float>::From(GetGestureDragVector());
}

float rfe::Gestures::GetDragAngle()
{
	return GetGestureDragAngle();
}

rfe::Vector2D<float> rfe::Gestures::GetPinchVector()
{
	return Vector2D<float>::From(GetGesturePinchVector());
}

float rfe::Gestures::GetPinchAngle()
{
	return GetGesturePinchAngle();
}
