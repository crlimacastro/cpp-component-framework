#pragma once

namespace rfe
{
    // Inherit to create your own RFE Application
    // A static pointer to the app currently running can be retrieved with Application::GetRunningApp()
    // Overrides:
    // protected OnStart() [Required] -> Define Start functionality and load the starting Scene
    // protected OnUpdate() -> Called every Update before the Scene updates
    // protected OnStop() -> Called when the app stops
    class RFE_API Application
    {
    public:
        // Definition in ApplicationSettings.h and ApplicationSettings.cpp
        class Settings;

    public:
        Application() = default;
        ~Application();

        static Application *GetRunningApp();

        std::shared_ptr<Settings> GetSettings() const;

        void Start();
        void Stop();

    protected:
        virtual void OnStart() = 0;
        virtual void OnUpdate() {}
        virtual void OnStop() {}

    private:
        static Application *runningApp;

        std::shared_ptr<Settings> settings = std::make_shared<Settings>();
        
        void Update();

        // Memory Leak Detection Logic
    private:
        _CrtMemState checkpointPostRaylibInitWindow = _CrtMemState();
        void InitMemLeakDetection();
    };
}