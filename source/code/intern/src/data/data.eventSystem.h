
#pragma once

#include <list>

#include "data.event.h"
#include "data.eventListener.h"
#include "data.eventType.h"

namespace Data
{
    using EventListenerPair = std::pair<EventType::Enum, EventListener>;
    using EventListenerList = std::list<EventListenerPair>;

    class EventSystem
    {
        public:
            static EventSystem& GetInstance()
            {
                static EventSystem instance;
                return instance;
            };

        public:
            void Register(EventType::Enum type, EventListener listener);
            void Unregister(EventType::Enum type, EventListener listener);

        public:
            void FireEvent(Event& event);
            void FireEvent(EventType::Enum type);
            void FireEvent(EventType::Enum type, int data);

            void AddEvent(Event& event);
            void ProcessEvents();

        private:
            EventSystem();
           ~EventSystem();

        private:
            EventSystem(const EventSystem&) = delete;
            EventSystem& operator = (const EventSystem&) = delete;

            std::list<Event> events;
            EventListenerList eventListeners;
    };
}
