#include "pch.h"
#include "FPSDrawer.hpp"

#include "Entity.hpp"
#include "Transform.hpp"

void rfe::FPSDrawer::OnDrawScreen()
{
	auto &position = GetEntity()->GetComponent<Transform>()->position;
	DrawFPS(position.x, position.y);
}