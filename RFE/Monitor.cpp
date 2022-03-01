#include "pch.h"
#include "Monitor.h"

rfe::Vector2D<float> rfe::Monitor::GetPosition() const
{
    Vector2 position = GetMonitorPosition(monitor);
    return Vector2D<float>{position.x, position.y};
}

int rfe::Monitor::GetWidth() const
{
    return GetMonitorWidth(monitor);
}

int rfe::Monitor::GetHeight() const
{
    return GetMonitorHeight(monitor);
}

int rfe::Monitor::GetPhysicalWidth() const
{
    return GetMonitorPhysicalWidth(monitor);
}

int rfe::Monitor::GetPhysicalHeight() const
{
    return GetMonitorPhysicalHeight(monitor);
}

int rfe::Monitor::GetRefreshRate() const
{
    return GetMonitorRefreshRate(monitor);
}

const char* rfe::Monitor::GetName() const
{
    return GetMonitorName(monitor);
}

const std::vector<rfe::Monitor> rfe::Monitors::GetMonitors()
{
    std::vector<Monitor> monitors;
    int monitorCount = GetMonitorCount();
    for (int i = 0; i < monitorCount; i++)
    {
        monitors.push_back(Monitor{ i });
    }
    return monitors;
}