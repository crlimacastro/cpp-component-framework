#include "pch.h"
#include "Vector3f.h"

bool rfe::Vector3f::operator==(const rfe::Vector3f& rhs) const
{
    return (x == rhs.x && y == rhs.y && z == rhs.z);
}

bool rfe::Vector3f::operator!=(const rfe::Vector3f& rhs) const
{
    return !(*this == rhs);
}

rfe::Vector3f rfe::Vector3f::operator+(const rfe::Vector3f& rhs) const
{
    return { x + rhs.x, y + rhs.y, z + rhs.z };
}

rfe::Vector3f& rfe::Vector3f::operator+=(const rfe::Vector3f& rhs)
{
    return *this = *this + rhs;
}

rfe::Vector3f rfe::Vector3f::operator-(const rfe::Vector3f& rhs) const
{
    return { x - rhs.x, y - rhs.y, z - rhs.z };
}

rfe::Vector3f& rfe::Vector3f::operator-=(const rfe::Vector3f& rhs)
{
    return *this = *this - rhs;
}

rfe::Vector3f rfe::Vector3f::operator*(const float rhs) const
{
    return { x * rhs, y * rhs, z * rhs };
}

rfe::Vector3f& rfe::Vector3f::operator*=(const float& rhs)
{
    return *this = *this * rhs;
}

rfe::Vector3f rfe::Vector3f::operator/(const float rhs) const
{
    return { x / rhs, y / rhs, z / rhs };
}

rfe::Vector3f& rfe::Vector3f::operator/=(const float& rhs)
{
    return *this = *this / rhs;
}