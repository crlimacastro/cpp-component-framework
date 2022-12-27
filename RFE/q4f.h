#pragma once

namespace rfe
{
	// Quaternion Float
	struct RFE_API q4f
	{
		float x = 0, y = 0, z = 0, w = 0;

	public:
		q4f() = default;
		q4f(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
		q4f(Quaternion other) : x(other.x), y(other.y), z(other.z), w(other.w) {}

	public:
		operator Quaternion() const { return { x, y, z, w }; }
	};
}