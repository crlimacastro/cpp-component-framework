#pragma once

#include "Vector2D.h"

namespace rfe
{
    class RFE_API Monitor
    {
    public:
        Monitor(int monitor = 0) : monitor(monitor) {}
        Vector2D<float> GetPosition() const;
        int GetWidth() const;
        int GetHeight() const;
        int GetPhysicalWidth() const;
        int GetPhysicalHeight() const;
        int GetRefreshRate() const;
        const char* GetName() const;

    private:
        int monitor;
    };

    class RFE_API Monitors
    {
    public:
        static const std::vector<Monitor> GetMonitors();
    private:
        Monitors() = delete;
        Monitors(const Monitors&) = delete;
        Monitors& operator=(const Monitors&) = delete;
        ~Monitors() = delete;
    };
}