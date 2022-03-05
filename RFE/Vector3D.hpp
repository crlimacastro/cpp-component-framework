#pragma once
#include "VectorND.hpp"

namespace rfe
{
	template <typename T>
	struct Vector3D : VectorND<3, T>
	{
		union {
			T data[3];
			struct {
				T x;
				T y;
				T z;
			};
		};

		Vector3D() = default;
		Vector3D(T x, T y, T z) : x(x), y(y), z(z) {}

		static Vector3D Up()
		{
			return { 0, 1, 0 };
		}

		static Vector3D Right()
		{
			return { 1, 0, 0 };
		}

		static Vector3D Forward()
		{
			return { 0, 0, 1 };
		}

		operator Vector3() const { return { x, y, z }; }
	};
}