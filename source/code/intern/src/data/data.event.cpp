#include "data.event.h"

namespace Data 
{
    void Event::SetType(EventType::Enum type)
    {
        this->type = type;
    }

    EventType::Enum Event::GetType() const
    {
        return type;
    }

    void Event::SetData(int data)
    {
        this->data = data;
    }

    int Event::GetData() const
    {
        return data;
    }
}