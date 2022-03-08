#pragma once
#include "VectorND.hpp"

namespace rfe
{
	template <typename T>
	struct Vector3D : VectorND<3, T>
	{
		T& x = VectorND<3, T>::data[0];
		T& y = VectorND<3, T>::data[1];
		T& z = VectorND<3, T>::data[2];

		Vector3D() = default;
		Vector3D(T x, T y, T z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
		Vector3D& operator=(const Vector3D& other)
		{
			x = other.x;
			y = other.y;
			z = other.z;
			return *this;
		}

		static Vector3D From(Vector3 other) {
			return { other.x, other.y, other.z };
		}

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