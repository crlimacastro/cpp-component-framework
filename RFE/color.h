#pragma once
#include "raylib.h"

namespace rfe
{
	// RFE Color
	struct RFE_API color
	{
		uint8_t r = 0, g = 0, b = 0, a = 255;

	public:
		color() = default;
		color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) : r(r), g(g), b(b), a(a) {}
		color(Color other) : r(other.r), g(other.g), b(other.b), a(other.a) {}

	public:
		operator Color() const { return { r, g, b, a }; }

	public:
		static color LightGray() { return { 200, 200, 200 }; }
		static color Gray() { return { 130, 130, 130 }; }
		static color DarkGray() { return { 80, 80, 80 }; }
		static color Yellow() { return { 253, 249, 0 }; }
		static color Gold() { return { 255, 203, 0 }; }
		static color Orange() { return { 255, 161, 0 }; }
		static color Pink() { return { 255, 109, 194 }; }
		static color Red() { return { 230, 41, 55 }; }
		static color Maroon() { return { 190, 33, 55 }; }
		static color Green() { return { 0, 228, 48 }; }
		static color Lime() { return { 0, 158, 47 }; }
		static color DarkGreen() { return { 0, 117, 44 }; }
		static color SkyBlue() { return { 102, 191, 255 }; }
		static color Blue() { return { 0, 121, 241 }; }
		static color DarkBlue() { return { 0, 82, 172 }; }
		static color CornflowerBlue() { return { 39, 58, 93 }; }
		static color Purple() { return { 200, 122, 255 }; }
		static color Violet() { return { 135, 60, 190 }; }
		static color DarkPurple() { return { 112, 31, 126 }; }
		static color Magenta() { return { 255, 0, 255 }; }
		static color Beige() { return { 211, 176, 131 }; }
		static color Brown() { return { 127, 106, 79 }; }
		static color DarkBrown() { return { 76, 63, 47 }; }
		static color White() { return { 255, 255, 255 }; }
		static color RayWhite() { return { 245, 245, 245 }; }
		static color Black() { return { 0, 0, 0 }; }
		static color Transparent() { return { 0, 0, 0, 0 }; }
	};
}