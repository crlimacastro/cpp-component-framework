#include "pch.h"
#include "CameraComponent.h"

#include "Entity.h"
#include "Application.h"
#include "Transform.h"

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