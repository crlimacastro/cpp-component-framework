#pragma once

// Mouse Cursor
namespace rfe
{
	class RFE_API Cursor
	{
	public:
		static void Show();
		static void Hide();
		static bool IsVisible();
		static void ToggleVisible();
		static void Enable();
		static void Disable();
		static bool IsOnScreen();
	private:
		Cursor() = delete;
		Cursor(const Cursor&) = delete;
		Cursor& operator=(const Cursor&) = delete;
		~Cursor() = delete;
	};
}