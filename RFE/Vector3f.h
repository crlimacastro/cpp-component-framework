#pragma once

namespace rfe
{
    struct RFE_API Vector3f
    {
        float x;
        float y;
        float z;

        constexpr Vector3f() {}
        constexpr Vector3f(float x, float y, float z) : x(x), y(y), z(z) {}

        constexpr bool operator==(const Vector3f& rhs) const
        {
            return (x == rhs.x && y == rhs.y && z == rhs.z);
        }
        constexpr bool operator!=(const Vector3f& rhs) const
        {
            return !(*this == rhs);
        }
        constexpr Vector3f operator+(const Vector3f& rhs) const
        {
            return { x + rhs.x, y + rhs.y, z + rhs.z };
        }
        constexpr Vector3f& operator+=(const Vector3f& rhs)
        {
            return *this = *this + rhs;
        }
        constexpr Vector3f operator-(const Vector3f& rhs) const
        {
            return { x - rhs.x, y - rhs.y, z - rhs.z };
        }
        constexpr Vector3f& operator-=(const Vector3f& rhs)
        {
            return *this = *this - rhs;
        }
        constexpr Vector3f operator*(const float rhs) const
        {
            return { x * rhs, y * rhs, z * rhs };
        }
        constexpr Vector3f& operator*=(const float& rhs)
        {
            return *this = *this * rhs;
        }
        constexpr Vector3f operator/(const float rhs) const
        {
            return { x / rhs, y / rhs, z / rhs };
        }
        constexpr Vector3f& operator/=(const float& rhs)
        {
            return *this = *this / rhs;
        }
    };
}