#pragma once

namespace rfe
{
	// Vector 2 Float
	struct RFE_API v2f
	{
		float x = 0, y = 0;

	public:
		v2f() = default;
		v2f(float x, float y) : x(x), y(y) {}
		v2f(Vector2 other) : x(other.x), y(other.y) {}

	public:
		static v2f Zero() { return { 0, 0 }; }
		static v2f One() { return { 1, 1 }; }
		static v2f Up() { return { 0, 1 }; }
		static v2f Down() { return { 0, -1 }; }
		static v2f Left() { return { -1, 0 }; }
		static v2f Right() { return { 1, 0 }; }

	public:
		operator Vector2() const { return { x, y }; }
	};
}