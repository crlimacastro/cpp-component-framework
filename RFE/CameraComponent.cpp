#include "pch.h"
#include "CameraComponent.hpp"

#include "Entity.hpp"
#include "Application.hpp"
#include "Transform.hpp"

void rfe::CameraComponent::OnEnable()
{
    Application::GetActive()->cameras.Push(camera);
}

void rfe::CameraComponent::OnDisable()
{
    Application::GetActive()->cameras.Remove(camera);
}

void rfe::CameraComponent::OnUpdate()
{
    camera.SetPosition(GetEntity()->GetComponent<Transform>()->position);
}