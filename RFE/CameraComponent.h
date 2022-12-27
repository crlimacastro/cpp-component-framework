#pragma once

#include "Component.h"
#include "Camera.h"

namespace rfe
{
	class Camera;

	class RFE_API CameraComponent : public Component
	{
	public:
		Camera camera;
	protected:
		void OnEnable() override;
		void OnDisable() override;
		void OnUpdate() override;
	};
}