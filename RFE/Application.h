#pragma once

namespace rfe
{
    // Inherit to create your own RFE Application
    // Override protected OnStart() to define functionality
    class RFE_API Application
    {
    public:
        Application() = default;

        void Start();
        const Color& GetClearColor() const;
        void SetClearColor(const Color& value);
        int GetTargetFPS() const;
        void TargetFPS(int value);
        bool HasVsync() const;
        void SetVsync(bool value);
        int GetStopKey() const;
        void SetStopKey(int value);

    protected:
        virtual void OnStart() = 0;

    private:
        Color clearColor = RAYWHITE;
        int targetFPS = -1;
        bool vsync = false;
        int stopKey = KEY_NULL;

        void Update();
        void Stop();
    };
}