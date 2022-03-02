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

    namespace Monitors
    {
        RFE_API const std::vector<Monitor> GetMonitors();
    }
}