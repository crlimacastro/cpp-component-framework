#pragma once

#include "Component.hpp"
#include "Keyboard.hpp"

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