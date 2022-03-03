#pragma once

namespace rfe
{
    template <typename T>
    struct Quaternion
    {
        T x;
        T y;
        T z;
        T w;

        Quaternion() = default;
        Quaternion(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
    };
}