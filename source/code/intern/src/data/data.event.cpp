#include "data.event.h"

namespace Data 
{
    void Event::SetType(BTypeID typeId)
    {
        typeId = typeId;
    }

    Event::BTypeID Event::GetType() const
    {
        return typeId;
    }
}