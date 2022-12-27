#include "pch.h"
#include "CameraStack.h"

#include "Camera.h"

rfe::Camera* rfe::CameraStack::GetActive() const
{
	if (cameras.size() > 0)
	{
		return cameras[cameras.size() - 1];
	}

	return nullptr;
}

void rfe::CameraStack::Push(Camera& camera)
{
	if (!cameraSet.contains(&camera))
	{
		// If set does not contain camera, add it to set and to end of the stack
		cameraSet.insert(&camera);
		cameras.push_back(&camera);
	}
	else
	{
		// If camera in set, move it to the end of the stack
		auto it = std::find(cameras.begin(), cameras.end(), &camera);
		std::rotate(it, it + 1, cameras.end());
	}
}

void rfe::CameraStack::Remove(Camera& camera)
{
	// If camera in set, remove it from set and stack
	if (cameraSet.contains(&camera))
	{
		cameraSet.erase(&camera);
		cameras.erase(std::remove(cameras.begin(), cameras.end(), &camera), cameras.end());
	}
}