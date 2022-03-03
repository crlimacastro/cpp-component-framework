#pragma once

#include "Component.h"

namespace rfe
{
	class RFE_API CameraComponent : public Component
	{
	public:
		Camera3D camera = { 0 };
	protected:
		void OnLoad() override;
		void OnUpdate() override;
	private:
	};
}