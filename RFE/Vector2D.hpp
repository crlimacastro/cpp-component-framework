#pragma once
#include "VectorND.hpp"

namespace rfe
{
    template <typename T>
    struct Vector2D : VectorND<2, T>
    {
		union {
			T data[2];
			struct {
				T x;
				T y;
			};
		};

		Vector2D() = default;
		Vector2D(T x, T y) : x(x), y(y) {}

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