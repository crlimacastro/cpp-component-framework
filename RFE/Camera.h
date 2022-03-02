#pragma once

#include "Component.h"

namespace rfe
{
	class RFE_API Camera : public Component
	{
	protected:
		void OnLoad() override;
		void OnUpdate() override;
	private:
		Camera3D camera = { 0 };
	};
}