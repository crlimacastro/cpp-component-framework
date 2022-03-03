#pragma once

namespace rfe
{
    struct RFE_API Vector3f
    {
        float x;
        float y;
        float z;

        Vector3f() = default;
        Vector3f(float x, float y, float z) : x(x), y(y), z(z) {}

        bool operator==(const Vector3f& rhs) const;
        bool operator!=(const Vector3f& rhs) const;
        Vector3f operator+(const Vector3f& rhs) const;
        Vector3f& operator+=(const Vector3f& rhs);
        Vector3f operator-(const Vector3f& rhs) const;
        Vector3f& operator-=(const Vector3f& rhs);
        Vector3f operator*(const float rhs) const;
        Vector3f& operator*=(const float& rhs);
        Vector3f operator/(const float rhs) const;
        Vector3f& operator/=(const float& rhs);
    };
}