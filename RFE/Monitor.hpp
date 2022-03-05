#pragma once

namespace rfe
{
    template <typename T>
    struct Vector2D;

    // Private constructor. Get monitor with public static Monitor::Get(int monitor = 0).
    // Will return nullptr if not a valid monitor number.
    class RFE_API Monitor
    {
    public:
        static std::shared_ptr<Monitor> Get(int monitor = 0);
        Vector2D<float> GetPosition() const;
        int GetWidth() const;
        int GetHeight() const;
        int GetPhysicalWidth() const;
        int GetPhysicalHeight() const;
        int GetRefreshRate() const;
        const char* GetName() const;

    private:
        Monitor(int monitor = 0) : monitor(monitor) {}
        int monitor;
    };

    namespace Monitors
    {
        RFE_API const std::shared_ptr<std::vector<std::shared_ptr<Monitor>>> GetMonitors();
    }
}