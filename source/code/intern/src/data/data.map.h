
#pragma once

#include "data.entityCategory.h"
#include "data.entityIterator.h"
#include "data.sector.h"

#include "../core/core.aabb.h"

namespace Data
{
    class Map
    {
        public:
            EntityIterator BeginEntity(Core::AABB2Float& rAABB, EntityCategory::Enum category);
            EntityIterator NextEntity(EntityIterator where, Core::AABB2Float& rAABB, EntityCategory::Enum category);

            EntityIterator BeginEntity(Core::AABB2Float& rAABB);
            EntityIterator NextEntity(EntityIterator where, Core::AABB2Float& rAABB);

            EntityIterator EndEntity();

        private:
            Sector sectors[4 * 8];        // Use constants or create dynamic array
    };
}

