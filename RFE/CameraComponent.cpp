#include "pch.h"
#include "CameraComponent.hpp"

#include "Entity.hpp"
#include "Application.hpp"

void rfe::CameraComponent::OnLoad()
{
    if (!transform)
    {
        transform = GetEntity()->GetComponent<rfe::Transform>();
    }
}

void rfe::CameraComponent::OnEnable()
{
    Application::GetActive()->Cameras.Push(camera);
}

void rfe::CameraComponent::OnDisable()
{
    Application::GetActive()->Cameras.Remove(camera);
}

void rfe::CameraComponent::OnUpdate()
{
    camera.SetPosition(transform->position);
    camera.Update();
}