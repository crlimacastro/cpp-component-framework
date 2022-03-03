#include "pch.h"
#include "CameraComponent.h"

#include "Component.h"

void rfe::CameraComponent::OnLoad()
{
    camera.position = Vector3{ 10.0f, 10.0f, 8.0f };
    camera.target = Vector3{ 0.0f, 0.0f, 0.0f };
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    //SetCameraMode(camera, CAMERA_ORBITAL);
}

void rfe::CameraComponent::OnUpdate()
{
    //UpdateCamera(&camera);
    BeginMode3D(camera);
    //DrawCube(Vector3{ 0, 0, 0 }, 2.0f, 2.0f, 2.0f, RED);
    //DrawCubeWires(Vector3{ 0, 0, 0 }, 2.0f, 2.0f, 2.0f, MAROON);
    DrawGrid(10, 1.0f);
    EndMode3D();
}