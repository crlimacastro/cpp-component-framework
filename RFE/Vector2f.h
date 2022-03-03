#pragma once

namespace rfe
{
    struct RFE_API Vector2f
    {
        float x;
        float y;

        Vector2f() = default;
        Vector2f(float x, float y) : x(x), y(y) {}
    };
}