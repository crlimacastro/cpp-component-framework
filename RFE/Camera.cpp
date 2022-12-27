#include "pch.h"
#include "Camera.h"

#include "v2f.h"
#include "v3f.h"
#include "Window.h"

void rfe::Camera::SetPosition(rfe::v3f value)
{
	context3D.camera3D.position = value;
	context2D.camera2D.target = { value.x, value.y };
}

void rfe::Camera::Update()
{
	UpdateCamera(&context3D.camera3D);
	context2D.camera2D.offset = { Window::GetWidth() * 0.5f, Window::GetHeight() * 0.5f };
}

rfe::Camera::Context3D::Context3D()
{
	camera3D.up = { 0.0f, 1.0f, 0.0f };
	camera3D.fovy = 60.0f;
}

void rfe::Camera::Context3D::BeginDrawing()
{
	BeginMode3D(camera3D);
}

void rfe::Camera::Context3D::EndDrawing()
{
	EndMode3D();
}

rfe::v3f rfe::Camera::Context3D::GetPosition() const
{
	return v3f(camera3D.position);
}

rfe::v3f rfe::Camera::Context3D::GetTarget() const
{
	return v3f(camera3D.target);
}

void rfe::Camera::Context3D::SetTarget(v3f value)
{
	camera3D.target = value;
}

rfe::v3f rfe::Camera::Context3D::GetUp() const
{
	return v3f(camera3D.up);
}

void rfe::Camera::Context3D::SetUp(v3f value)
{
	camera3D.up = value;
}

float rfe::Camera::Context3D::GetFOV() const
{
	return camera3D.fovy;
}

void rfe::Camera::Context3D::SetFOX(float value)
{
	camera3D.fovy = value;
}

rfe::Camera::Context3D::Projection rfe::Camera::Context3D::GetProjection() const
{
	return static_cast<Projection>(camera3D.projection);
}

void rfe::Camera::Context3D::SetProjection(Projection value)
{
	camera3D.projection = static_cast<int>(value);
}

rfe::Camera::Context3D::Mode rfe::Camera::Context3D::GetMode() const
{
	return cameraMode;
}

void rfe::Camera::Context3D::SetMode(Mode value)
{
	cameraMode = value;
	SetCameraMode(camera3D, static_cast<int>(value));
}

Ray rfe::Camera::Context3D::GetMouseRaycast() const
{
	return GetMouseRay(GetMousePosition(), camera3D);
}

Matrix rfe::Camera::Context3D::GetMatrix() const
{
	return GetCameraMatrix(camera3D);
}

rfe::v2f rfe::Camera::Context3D::GetWorldToScreenPoint(v3f position) const
{
	return v2f(GetWorldToScreen(position, camera3D));
}

rfe::Camera::Context2D::Context2D()
{
	camera2D.zoom = 1.0f;
}

void  rfe::Camera::Context2D::BeginDrawing()
{
	BeginMode2D(camera2D);
}

void rfe::Camera::Context2D::EndDrawing()
{
	EndMode2D();
}

rfe::v2f rfe::Camera::Context2D::GetPosition() const
{
	return v2f(camera2D.target);
}

float rfe::Camera::Context2D::GetRotation() const
{
	return camera2D.rotation;
}

void rfe::Camera::Context2D::SetRotation(float value)
{
	camera2D.rotation = value;
}

float rfe::Camera::Context2D::GetZoom() const
{
	return camera2D.zoom;
}

void rfe::Camera::Context2D::SetZoom(float value)
{
	camera2D.zoom = value;
}

Matrix rfe::Camera::Context2D::GetMatrix() const
{
	return GetCameraMatrix2D(camera2D);
}

rfe::v2f rfe::Camera::Context2D::GetWorldToScreen(v2f position) const
{
	return GetWorldToScreen2D(position, camera2D);
}

rfe::v2f rfe::Camera::Context2D::GetScreenToWorld(v2f position) const
{
	return GetScreenToWorld2D(position, camera2D);
}