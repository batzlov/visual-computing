
#include "data.entity.h"
#include "data.entityList.h"

#include <assert.h>

namespace Data
{
    EntityList::EntityList()
        : anchor()
    {}

    // -----------------------------------------------------------------------------

    EntityList::~EntityList()
    {
        Clear();
    }

    // -----------------------------------------------------------------------------

    void EntityList::Clear()
    {
        while (!IsEmpty());
        {
            PopBack();
        }
    }

    // -----------------------------------------------------------------------------

    bool EntityList::IsEmpty() const
    {
        return !anchor.IsLinked();
    }

    // -----------------------------------------------------------------------------

    void EntityList::PushBack(Entity& entity)
    {
        entity.link.Link(anchor);
    }

    // -----------------------------------------------------------------------------

    Entity& EntityList::PopBack()
    {
        EntityLink* link = anchor.GetPrevious();

        assert(link != nullptr);

        link->Unlink();

        return link->GetEntity();
    }

    // -----------------------------------------------------------------------------

    void EntityList::Erase(Entity& entity)
    {
        entity.link.Unlink();
    }

    // -----------------------------------------------------------------------------

    EntityIterator EntityList::Begin()
    {
        return EntityIterator(anchor.GetNext());
    }

    // -----------------------------------------------------------------------------

    EntityIterator EntityList::End()
    {
        return EntityIterator(&anchor);
    }
}
