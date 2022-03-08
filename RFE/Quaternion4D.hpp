#pragma once
#include "VectorND.hpp"

namespace rfe
{
    template <typename T>
    struct Quaternion4D : VectorND<4, T>
    {
		T& x = VectorND<4, T>::data[0];
		T& y = VectorND<4, T>::data[1];
		T& z = VectorND<4, T>::data[2];
		T& w = VectorND<4, T>::data[3];

		Quaternion4D() = default;
		Quaternion4D(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

		static Quaternion4D From(Quaternion other) {
			return { other.x, other.y, other.z, other.w };
		}
    };
}