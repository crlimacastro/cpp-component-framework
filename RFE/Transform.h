#pragma once

#include "Component.h"

namespace rfe
{
    class RFE_API Transform : public Component
    {
    public:
        Vector3D<float> position;
        Quaternion<float> rotation;
        Vector3D<float> scale;
    };
}