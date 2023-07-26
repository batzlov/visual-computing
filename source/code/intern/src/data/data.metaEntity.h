#pragma once

#include <string>

#include "../core/core.aabb.h"

namespace Data 
{
    class MetaEntity
    {
        public:
            MetaEntity();
            MetaEntity(int _id, std::string _name, float _size, Core::AABB2Float _aabb);
            
            ~MetaEntity();

        public:
            int id;
            std::string name;
            float size;
            Core::AABB2Float aabb;

            void* facets[2];
    };
}