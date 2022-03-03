#pragma once

#include "Vector2f.h"

namespace rfe
{
    class RFE_API Monitor
    {
    public:
        static std::shared_ptr<Monitor> Get(int monitor = 0);
        Vector2f GetPosition() const;
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