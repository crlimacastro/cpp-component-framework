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
            for (auto& listener : listeners)
            {
                listener(args...);
            }
        }

    private:
        std::vector<std::function<void(Args...)>> listeners;
    };
}