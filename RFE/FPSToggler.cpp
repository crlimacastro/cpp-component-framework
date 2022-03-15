#include "pch.h"
#include "FPSToggler.hpp"

#include "Entity.hpp"
#include "FPSDrawer.hpp"

void rfe::FPSToggler::OnUpdate()
{
	if (Keyboard::KeyPressed(toggleKey))
	{
		auto fpsDrawer = GetEntity()->GetComponent<FPSDrawer>();

		fpsDrawer->SetEnabled(!fpsDrawer->GetEnabled());
	}
}