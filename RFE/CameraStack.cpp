#include "pch.h"
#include "CameraStack.h"

#include "Camera.hpp"

rfe::Camera* rfe::CameraStack::GetActive() const
{
	if (Cameras.size() > 0)
	{
		return Cameras[Cameras.size() - 1];
	}

	return nullptr;
}

void rfe::CameraStack::Push(Camera& camera)
{
	if (!cameraSet.contains(&camera))
	{
		// If set does not contain camera, add it to set and to end of the stack
		cameraSet.insert(&camera);
		Cameras.push_back(&camera);
	}
	else
	{
		// If camera in set, move it to the end of the stack
		auto it = std::find(Cameras.begin(), Cameras.end(), &camera);
		std::rotate(it, it + 1, Cameras.end());
	}
}

void rfe::CameraStack::Remove(Camera& camera)
{
	// If camera in set, remove it from set and stack
	if (cameraSet.contains(&camera))
	{
		cameraSet.erase(&camera);
		Cameras.erase(std::remove(Cameras.begin(), Cameras.end(), &camera), Cameras.end());
	}
}