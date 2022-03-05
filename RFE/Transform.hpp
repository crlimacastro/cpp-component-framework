#pragma once

#include "Component.hpp"

#include "Vector3D.hpp"
#include "Quaternion.hpp""

namespace rfe
{
    class RFE_API Transform : public Component
    {
    public:
        Vector3D<float> position;
        Quaternion<float> rotation;
        Vector3D<float> scale{1, 1, 1};
    };
}