#include "pch.h"
#include "Application.h"

#include "Window.h"
#include "SceneManager.h"
#include "ApplicationSettings.h"

rfe::Application* rfe::Application::runningApp = nullptr;

rfe::Application* rfe::Application::GetRunningApp()
{
	return runningApp;
}

std::shared_ptr<rfe::Application::Settings> rfe::Application::GetSettings() const
{
	return settings;
}

void rfe::Application::Start()
{
	runningApp = this;

	Window::Open();

	// Init Settings
	SetTargetFPS(settings->GetTargetFPS());
	settings->SetVsync(settings->HasVsync());
	SetExitKey(settings->GetForceStopKey());

	OnStart();

	// Update Loop
	while (!Window::ShouldClose())
	{
		Update();
	}

	Stop();
}

void rfe::Application::Update()
{
	BeginDrawing();
	ClearBackground(settings->GetClearColor());

	OnUpdate();

	if (SceneManager::GetCurrentScene())
	{
		SceneManager::GetCurrentScene()->Update();
	}

	EndDrawing();
}

void rfe::Application::Stop()
{
	OnStop();
	SceneManager::GetCurrentScene()->Unload();
	Window::Close();
	runningApp = nullptr;
}