#pragma once

#include "Component.hpp"

namespace rfe
{
	class RFE_API FPSDrawer : public Component
	{
	public:
	protected:
		void OnDrawScreen() override;
	};
}