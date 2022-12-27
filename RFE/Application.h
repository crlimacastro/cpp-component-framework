#pragma once

#include "ApplicationSettings.h"
#include "CameraStack.h"

namespace rfe
{
	// Inherit to create your own RFE Application
	// A static pointer to the app currently running can be retrieved with Application::GetActive()
	// Overrides:
	// protected OnStart() [Required] -> Define Start functionality and load the starting Scene
	// protected OnStop() -> Called before the app completely stops
	class RFE_API Application
	{
	public:
		Application() = default;
		~Application();

		ApplicationSettings settings;
		CameraStack cameras;

		// Running Logic
	public:
		int GetCurrentFPS();
		void Start();
		void Stop();
	private:
		void Update();
		bool isStarted = false;
		bool isRunning = false;
		bool isStopped = false;

		// Static Application Logic
	public:
		static Application* GetActive();
	private:
		static Application* activeApp;

		// Callbacks
	protected:
		virtual void OnStart() = 0;
		virtual void OnStop() {}

	private:
		void InitSettings();

		// No copy/move
	private:
		Application(const Application& other) = delete;
		Application(Application&& other) noexcept = delete;
		Application& operator=(const Application& other) = delete;
		Application& operator=(Application&& other) noexcept = delete;

		// Memory Leak Detection Logic
	private:
		_CrtMemState memCheckpointPostRaylibInitWindow = _CrtMemState();
		void InitMemLeakDetection();
	};
}