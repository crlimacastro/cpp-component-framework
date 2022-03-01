#pragma once

namespace rfe
{
    template <typename T>
    struct RFE_API Vector2D
    {
        T x;
        T y;

        constexpr Vector2D() = default;
        constexpr Vector2D(T x, T y) : x(x), y(y) {}
    };
}