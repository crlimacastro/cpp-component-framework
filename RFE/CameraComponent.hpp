#pragma once

#include "Component.hpp"
#include "Transform.hpp"
#include "Camera.hpp"

namespace rfe
{
	class RFE_API CameraComponent : public Component
	{
	public:
		std::shared_ptr<rfe::Transform> transform;
	protected:
		void OnLoad() override;
		void OnEnable() override;
		void OnDisable() override;
		void OnUpdate() override;
	private:
		Camera camera;
	};
}