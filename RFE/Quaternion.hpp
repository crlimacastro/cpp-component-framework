#pragma once
#include "VectorND.hpp"

namespace rfe
{
    template <typename T>
    struct Quaternion : VectorND<4, T>
    {
		union {
			T data[4];
			struct {
				T x;
				T y;
				T z;
				T w;
			};
		};

		Quaternion() = default;
		Quaternion(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
    };
}