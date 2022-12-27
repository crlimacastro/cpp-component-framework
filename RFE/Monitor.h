#pragma once

namespace rfe
{
	struct v2f;

	// Private constructor. Get monitor with public static Monitor::Get(int monitor = 0).
	// Will return nullptr if not a valid monitor number.
	class RFE_API Monitor
	{
	public:
		static ref<Monitor> Get(int monitor = 0);
		v2f GetPosition() const;
		int GetWidth() const;
		int GetHeight() const;
		int GetPhysicalWidth() const;
		int GetPhysicalHeight() const;
		int GetRefreshRate() const;
		const char* GetName() const;

	private:
		Monitor(int monitor = 0) : monitor(monitor) {}
		int monitor;
	};

	namespace Monitors
	{
		RFE_API std::vector<ref<Monitor>> GetMonitors();
	}
}