#pragma once

namespace rfe
{
    struct RFE_API Quaternion
    {
        float x;
        float y;
        float z;
        float w;

        Quaternion() = default;
        Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
    };
}