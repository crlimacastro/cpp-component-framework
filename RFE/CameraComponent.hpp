#pragma once

#include "Component.hpp"
#include "Camera.hpp"

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