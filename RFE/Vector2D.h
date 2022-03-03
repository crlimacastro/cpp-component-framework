#pragma once

namespace rfe
{
    template <typename T>
    struct Vector2D
    {
        T x;
        T y;

        Vector2D() = default;
        Vector2D(T x, T y) : x(x), y(y) {}
    };
}