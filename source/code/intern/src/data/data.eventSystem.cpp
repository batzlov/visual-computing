#include "data.eventSystem.h"

#include <iostream>
#include <cassert>

namespace Data 
{
    EventSystem::EventSystem() {}
    EventSystem::~EventSystem() {}

    void EventSystem::Register(EventType::Enum type, EventListener listener)
    {
        eventListeners.push_back(std::make_pair(type, listener));
    }

    void EventSystem::Unregister(EventType::Enum type, EventListener listener)
    {
        for (auto it = eventListeners.begin(); it != eventListeners.end(); ++it)
        {
            if (it->first == type && it->second == listener)
            {
                eventListeners.erase(it);
                return;
            }
        }
    }

    void EventSystem::FireEvent(EventType::Enum type)
    {
        Event* event = nullptr;

        try
        {
            Event* event = new Event();
            event->SetType(type);

            FireEvent(*event);
        }
        catch (...)
        {
            std::cout << "Exception :(" << std::endl;
            delete event;
        }        
    }

    void EventSystem::FireEvent(EventType::Enum type, int data)
    {
        Event* event = nullptr;

        try
        {
            Event* event = new Event();
            event->SetType(type);
            event->SetData(data);

            FireEvent(*event);
        }
        catch (...)
        {
            std::cout << "Exception :(" << std::endl;
            delete event;
        }        
    }

    void EventSystem::FireEvent(Event& event)
    {
        for(auto& listener : eventListeners)
        {
            if (listener.first == event.GetType())
            {
                (*listener.second)(event);
            }
        }
    }

    void EventSystem::AddEvent(Event& event)
    {
        events.push_back(event);
    }

    void EventSystem::ProcessEvents()
    {
        for (auto& event : events)
        {
            FireEvent(event);
        }
    }
}