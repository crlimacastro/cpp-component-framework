#include "pch.h"
#include "FPSToggler.h"

#include "Entity.h"
#include "FPSDrawer.h"

void rfe::FPSToggler::OnUpdate()
{
	if (Keyboard::KeyPressed(toggleKey))
	{
		auto fpsDrawer = GetEntity()->GetComponent<FPSDrawer>();

		fpsDrawer->SetEnabled(!fpsDrawer->GetEnabled());
	}
}