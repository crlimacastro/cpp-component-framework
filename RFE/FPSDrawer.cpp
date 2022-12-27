#include "pch.h"
#include "FPSDrawer.h"

#include "Entity.h"
#include "Transform.h"

void rfe::FPSDrawer::OnDrawScreen()
{
	auto& position = GetEntity()->GetComponent<Transform>()->position;
	DrawFPS(position.x, position.y);
}