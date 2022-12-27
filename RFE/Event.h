#pragma once

namespace rfe
{
	template <typename... Args>
	class Event
	{
	public:
		Event() = default;

		void Subscribe(std::function<void(Args...)>&& listener)
		{
			listeners.push_back(listener);
		}

		void Unsubscribe(std::function<void(Args...)>& listener)
		{
			listeners.erase(std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
		}

		void Invoke(Args... args)
		{
			for (int i = listeners.size() - 1; i >= 0; i--)
			{
				listeners[i](args...);
			}
		}

		void Clear()
		{
			listeners.clear();
		}

		Event& operator=(std::function<void(Args...)>&& listener)
		{
			listeners.clear();
			listeners.push_back(listener);
			return *this;
		}

		Event& operator=(std::function<void(Args...)>* listener)
		{
			listeners.clear();
			if (listener)
			{
				listeners.push_back(*listener);
			}
			return *this;
		}

		Event& operator+=(std::function<void(Args...)>&& listener) {

			listeners.push_back(listener);
			return *this;
		}

		Event& operator-=(std::function<void(Args...)>& listener) {

			listeners.erase(std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
			return *this;
		}

		Event& operator()(Args... args) {
			for (int i = listeners.size() - 1; i >= 0; i--)
			{
				listeners[i](args...);
			}
			return *this;
		}

	private:
		std::vector<std::function<void(Args...)>> listeners;
	};
}