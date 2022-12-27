#pragma once

#include "Component.h"
#include "Keyboard.h"

namespace rfe
{
	class RFE_API FPSToggler : public rfe::Component
	{
	public:
		Keyboard::Key toggleKey = Keyboard::Key::OemTilde;
	protected:
		void OnUpdate() override;
	};
}