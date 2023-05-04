#pragma once

#include <string>

namespace Data 
{
    class MetaEntity
    {
        public:
            MetaEntity();
            MetaEntity(int id, std::string name);
            
            ~MetaEntity();

        // public:
        //     GetId();
        //     SetId(int id);

        //     GetName();
        //     SetName(std::string name);

        public:
            int id;
            std::string name;

            void* facets[2];
    };
}