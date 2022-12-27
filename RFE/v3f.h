#pragma once
#include "raylib.h"

namespace rfe
{
	// Vector 3 Float
	struct RFE_API v3f
	{
		float x = 0, y = 0, z = 0;

	public:
		v3f() = default;
		v3f(float x, float y, float z) : x(x), y(y), z(z) {}
		v3f(Vector3 other) : x(other.x), y(other.y), z(other.z) {}

	public:
		static v3f Zero() { return { 0, 0, 0 }; }
		static v3f One() { return { 1, 1, 1 }; }
		static v3f Up() { return { 0, 1, 0 }; }
		static v3f Down() { return { 0, -1, 0 }; }
		static v3f Left() { return { -1, 0, 0 }; }
		static v3f Right() { return { 1, 0, 0 }; }
		static v3f Forward() { return { 0, 0, 1 }; }
		static v3f Back() { return { 0, 0, -1 }; }

	public:
		float GetMagnitude() const { return sqrt(x * x + y * y + z * z); }
		float GetSqrMagnitude() const { return x * x + y * y + z * z; }
		void SetMagnitude(float value)
		{
			auto mag = GetMagnitude();
			if (mag == 0)
			{
				return;
			}

			auto scale = value / mag;
			x *= scale;
			y *= scale;
			z *= scale;
		}
		void Normalize()
		{
			auto mag = GetMagnitude();
			if (mag == 0) return;

			x /= mag;
			y /= mag;
			z /= mag;
		}
		v3f GetNormalized() const
		{
			auto mag = GetMagnitude();
			if (mag == 0) return {};
			return { x / mag, y / mag, z / mag };
		}

	public:
		bool operator==(const v3f& other) const { return x == other.x && y == other.y && z == other.z; }
		bool operator!=(const v3f& other) const { return !(*this == other); }
		v3f operator+(const v3f& other) const { return { x + other.x, y + other.y, z + other.z }; }
		v3f& operator+=(const v3f& other) { return *this = *this + other; }
		v3f operator-(const v3f& other) const { return { x - other.x, y - other.y, z - other.z }; }
		v3f& operator-=(const v3f& other) { return *this = *this - other; }
		v3f operator*(const float other) const { return { x * other, y * other, z * other }; }
		v3f& operator*=(const float other) { return *this = *this * other; }
		v3f operator/(const float other) const { return { x / other, y / other, z / other }; }
		v3f& operator/=(const float other) { return *this = *this / other; }
		operator Vector3() const { return { x, y, z }; }
	};
}