
#include "data.map.h"

namespace Data
{
    EntityIterator Map::BeginEntity(AABB2Float& rAABB, EntityCategory::Enum category)
    {
        // Get first sector within AABB which contains an entity within the entity list of the given category
        // return iterator to this entity, otherwise return end iterator


        return EndEntity();
    }

    // -----------------------------------------------------------------------------

    EntityIterator Map::NextEntity(EntityIterator where, AABB2Float& rAABB, EntityCategory::Enum category)
    {
        return EndEntity();
    }

    // -----------------------------------------------------------------------------

    EntityIterator Map::BeginEntity(AABB2Float& rAABB)
    {
        return EndEntity();
    }

    // -----------------------------------------------------------------------------

    EntityIterator Map::NextEntity(EntityIterator where, AABB2Float& rAABB)
    {
        return EndEntity();
    }

    // -----------------------------------------------------------------------------

    EntityIterator Map::EndEntity()
    {
        return EntityIterator();
    }
}

