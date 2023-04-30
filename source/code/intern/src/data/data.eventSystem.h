
#pragma once

#include "data.event.h"
#include "data.eventListener.h"

namespace Data
{
    class EventSystem
    {
        public:
            static EventSystem& GetInstance();

        public:
            void Register(Event::BTypeID typeId, EventListener listener);
            void Unregister(Event::BTypeID typeId, EventListener listener);

        public:
            Event& MakeEvent();
            void FireEvent(Event& event);
            void AddEvent(Event& event);
            void ProcessEvents();

        private:
            EventSystem();
           ~EventSystem();

        private:
            EventSystem(const EventSystem&) = delete;
            EventSystem& operator = (const EventSystem&) = delete;
    };
}
