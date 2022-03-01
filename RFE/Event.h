#pragma once

//namespace rfe
//{
//    template <typename... ParameterTypes>
//    class RFE_API Event
//    {
//        using Listener = std::function<ParameterTypes...>;
//
//    public:
//        Event() = default;
//
//        void Subscribe(const Listener& listener) const
//        {
//            listeners.push_back(listener);
//        }
//
//        void Unsubscribe(Listener& listener) const
//        {
//            listeners.erase(std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
//        }
//
//        void Invoke(ParameterTypes... parameters) const
//        {
//            for (auto&& listener : listeners)
//            {
//                listener(parameters...);
//            }
//        }
//
//    private:
//        std::vector<Listener*> listeners;
//    };
//}