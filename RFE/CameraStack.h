#pragma once

namespace rfe
{
	class Camera;

	// Use public static Camera::GetActive() to get the currently active Camera from the Stack.
	// Use Cameras::Push(Camera*) and Cameras::Remove(Camera*) to interact with the Camera Stack.
	// The last Camera Pushed will be the active one.
	class RFE_API CameraStack
	{
	public:
		Camera* GetActive() const;

		// Push a Camera to the Camera Stack and set it as the active one
		void Push(Camera& camera);
		// Remove a Camera from the Camera Stack
		void Remove(Camera& camera);
	private:
		std::unordered_set<rfe::Camera*> cameraSet;
		std::vector<rfe::Camera*> Cameras;
	};
}