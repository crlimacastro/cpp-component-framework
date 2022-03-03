#include "pch.h"
#include "Application.h"

#include "Window.h"
#include "SceneManager.h"
#include "ApplicationSettings.h"
#include "Log.h"

rfe::Application* rfe::Application::runningApp = nullptr;

rfe::Application::~Application()
{
	RFE_LOG("Heap state on ~Application()");
	_CrtMemDumpAllObjectsSince(&checkpointPostRaylibInitWindow);
}

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

	InitMemLeakDetection();

	// Init Settings
	SetTargetFPS(settings->GetTargetFPS());
	settings->SetVsync(settings->HasVsync());
	SetExitKey(settings->GetForceStopKey());

	OnStart();

	// Start Update Loop
	while (!Window::ShouldClose())
	{
		Update();
	}

	// Call Stop on Window close
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
	SceneManager::UnloadScene();
	Window::Close();
	runningApp = nullptr;
}

void rfe::Application::InitMemLeakDetection()
{
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	_CrtMemCheckpoint(&checkpointPostRaylibInitWindow);
}