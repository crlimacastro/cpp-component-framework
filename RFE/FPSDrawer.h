#pragma once

#include "Component.h"

namespace rfe
{
	class RFE_API FPSDrawer : public Component
	{
	public:
	protected:
		void OnDrawScreen() override;
	};
}