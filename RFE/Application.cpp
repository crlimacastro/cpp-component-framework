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
	RFE_LOG_INFO("Heap state on ~Application()");
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
	ClearBackground(settings.GetClearColor());

	if (cameras.GetActive())
	{
		cameras.GetActive()->Update();
	}

	OnUpdate();

	if (sceneManager.GetCurrentScene())
	{
		sceneManager.GetCurrentScene()->Update();
	}

	if (cameras.GetActive())
	{
		cameras.GetActive()->context3D.BeginDrawing();
		fnBuffer3D.DumpInvoke();
		cameras.GetActive()->context3D.EndDrawing();
		cameras.GetActive()->context2D.BeginDrawing();
		fnBuffer2D.DumpInvoke();
		cameras.GetActive()->context2D.EndDrawing();
		fnBufferScreen.DumpInvoke();
	}

	EndDrawing();
	
	fnBufferPostDraw.DumpInvoke();
}

void rfe::Application::Stop()
{
	if (isStopped)
		return;

	isStopped = true;

	OnStop();

	sceneManager.UnloadScene();

	Window::Close();

	isRunning = false;
	activeApp = nullptr;
}

void rfe::Application::InitSettings()
{
	settings.TargetFPS(settings.GetTargetFPS());
	settings.SetVsync(settings.HasVsync());
	settings.SetForceStopKey(settings.GetForceStopKey());
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