#pragma once

namespace rfe
{
    template <typename T>
    struct RFE_API Vector3D
    {
        T x;
        T y;
        T z;

        constexpr Vector3D() = default;
        constexpr Vector3D(T x, T y, T z) : x(x), y(y), z(z) {}

        constexpr bool operator==(const Vector3D& rhs) const
        {
            return (x == rhs.x && y == rhs.y && z == rhs.z);
        }
        constexpr bool operator!=(const Vector3D& rhs) const
        {
            return !(*this == rhs);
        }
        constexpr Vector3D operator+(const Vector3D& rhs) const
        {
            return { x + rhs.x, y + rhs.y, z + rhs.z };
        }
        constexpr Vector3D& operator+=(const Vector3D& rhs)
        {
            return *this = *this + rhs;
        }
        constexpr Vector3D operator-(const Vector3D& rhs) const
        {
            return { x - rhs.x, y - rhs.y, z - rhs.z };
        }
        constexpr Vector3D& operator-=(const Vector3D& rhs)
        {
            return *this = *this - rhs;
        }
        constexpr Vector3D operator*(const T rhs) const
        {
            return { x * rhs, y * rhs, z * rhs };
        }
        constexpr Vector3D& operator*=(const T& rhs)
        {
            return *this = *this * rhs;
        }
        constexpr Vector3D operator/(const T rhs) const
        {
            return { x / rhs, y / rhs, z / rhs };
        }
        constexpr Vector3D& operator/=(const T& rhs)
        {
            return *this = *this / rhs;
        }
    };
}