#include "pch.h"
#include "Camera.hpp"

#include "Vector3D.hpp"

rfe::Camera::Camera()
{
	raylibCamera.position = { 0.0f, 0.0f, 0.0f };
	raylibCamera.target = { 0.0f, 0.0f, 0.0f };
	raylibCamera.up = { 0.0f, 1.0f, 0.0f };
	raylibCamera.fovy = 60.0f;
	SetProjection(Projection::Perspective);
	SetMode(Mode::Custom);
}

void rfe::Camera::BeginDrawing()
{
	BeginMode3D(raylibCamera);
}

void rfe::Camera::EndDrawing()
{
	EndMode3D();
}

rfe::Vector3D<float> rfe::Camera::GetPosition() const
{
	return { raylibCamera.position.x, raylibCamera.position.y, raylibCamera.position.z };
}

void rfe::Camera::SetPosition(Vector3D<float> value)
{
	raylibCamera.position = value;
}

float rfe::Camera::GetFOV() const
{
	return raylibCamera.fovy;
}

void rfe::Camera::SetFOX(float value)
{
	raylibCamera.fovy = value;
}

rfe::Camera::Projection rfe::Camera::GetProjection() const
{
	return static_cast<Projection>(raylibCamera.projection);
}

void rfe::Camera::SetProjection(Projection value)
{
	raylibCamera.projection = static_cast<int>(value);
}

rfe::Camera::Mode rfe::Camera::GetMode() const
{
	return cameraMode;
}

void rfe::Camera::SetMode(Mode value)
{
	cameraMode = value;
	SetCameraMode(raylibCamera, static_cast<int>(value));
}

void rfe::Camera::Update()
{
	UpdateCamera(&raylibCamera);
}