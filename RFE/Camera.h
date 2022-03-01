#pragma once

#include "Component.h"

namespace rfe
{
	struct RFE_API Camera : public Component
	{
	protected:
		void OnLoad() override;
		void OnUpdate() override;
	private:
		Camera3D camera = { 0 };
	};
}