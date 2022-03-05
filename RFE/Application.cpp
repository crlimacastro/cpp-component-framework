#include "pch.h"
#include "Application.hpp"

#include "Window.hpp"
#include "Monitor.hpp"
#include "Camera.hpp"
#include "SceneManager.hpp"
#include "Log.hpp"

rfe::Application* rfe::Application::activeApp = nullptr;

rfe::Application::~Application()
{
	RFE_LOG("Heap state on ~Application()");
	_CrtMemDumpAllObjectsSince(&memCheckpointPostRaylibInitWindow);
}

rfe::Application* rfe::Application::GetActive()
{
	return activeApp;
}

int rfe::Application::GetCurrentFPS()
{
	return GetFPS();
}

void rfe::Application::Start()
{
	if (isStarted)
		return;

	isStarted = true;
	isRunning = true;
	activeApp = this;

	Window::Open();
	InitMemLeakDetection();
	InitSettings();

	OnStart();
	// Start Update Loop
	while (isRunning)
	{
		if (Window::ShouldClose())
			break;

		Update();
	}
	// Call Stop on Window close
	Stop();
}

void rfe::Application::Update()
{
	BeginDrawing();
	ClearBackground(Settings.GetClearColor());

	if (Cameras.GetActive())
	{
		Cameras.GetActive()->BeginDrawing();
	}

	OnUpdate();

	if (SceneManager.GetCurrentScene())
	{
		SceneManager.GetCurrentScene()->Update();
	}

	if (Cameras.GetActive())
	{
		Cameras.GetActive()->EndDrawing();
	}
	EndDrawing();
}

void rfe::Application::Stop()
{
	if (isStopped)
		return;

	isStopped = true;

	OnStop();

	SceneManager.UnloadScene();

	Window::Close();

	isRunning = false;
	activeApp = nullptr;
}

void rfe::Application::InitSettings()
{
	Settings.TargetFPS(Settings.GetTargetFPS());
	Settings.SetVsync(Settings.HasVsync());
	Settings.SetForceStopKey(Settings.GetForceStopKey());
}

void rfe::Application::InitMemLeakDetection()
{
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	_CrtMemCheckpoint(&memCheckpointPostRaylibInitWindow);
}