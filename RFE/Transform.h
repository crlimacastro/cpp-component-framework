#pragma once

#include "Component.h"
#include "v3f.h"
#include "q4f.h"

namespace rfe
{
	class RFE_API Transform : public Component
	{
	public:
		v3f position;
		q4f rotation;
		v3f scale{ 1, 1, 1 };
	};
}