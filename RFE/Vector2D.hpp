#pragma once
#include "VectorND.hpp"

namespace rfe
{
    template <typename T>
    struct Vector2D : VectorND<2, T>
    {
		T& x = VectorND<2, T>::data[0];
		T& y = VectorND<2, T>::data[1];

		Vector2D() = default;
		Vector2D(T x, T y) : x(x), y(y) {}

		static Vector2D From(Vector2 other) {
			return { other.x, other.y };
		}

		static Vector2D Up()
		{
			return { 0, 1 };
		}

		static Vector2D Right()
		{
			return { 1, 0 };
		}

		static Vector2D Forward()
		{
			return { 0, 0, 1 };
		}

		operator Vector2() const { return { x, y }; }
    };
}