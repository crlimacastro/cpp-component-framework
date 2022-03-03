#include "pch.h"
#include "Monitor.h"

#include "Vector2f.h"

std::shared_ptr<rfe::Monitor> rfe::Monitor::Get(int monitor)
{
    if (monitor < 0 || monitor >= GetMonitorCount())
    {
        return nullptr;
    }

    return std::shared_ptr<Monitor>(new Monitor(monitor));
}

rfe::Vector2f rfe::Monitor::GetPosition() const
{
    Vector2 position = GetMonitorPosition(monitor);
    return Vector2f{position.x, position.y};
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

const std::shared_ptr<std::vector<std::shared_ptr<rfe::Monitor>>> rfe::Monitors::GetMonitors()
{
    auto monitors = std::make_shared<std::vector<std::shared_ptr<Monitor>>>();
    int monitorCount = GetMonitorCount();
    for (int i = 0; i < monitorCount; i++)
    {
        monitors->push_back(Monitor::Get(i));
    }
    return monitors;
}
