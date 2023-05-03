#include <iostream>
#include <tinyxml2.h>
#include <string>

#include "data.entitySystem.h"
#include "data.metaEntitySystem.h"

namespace Data 
{
    int EntitySystem::Initialize(tinyxml2::XMLDocument& document)
    {
        int entityCount = 0;

        Data::MetaEntitySystem& metaEntitySystem = Data::MetaEntitySystem::GetInstance();

        tinyxml2::XMLElement* entities = document.FirstChildElement("entities");
        tinyxml2::XMLElement* entity = entities->FirstChildElement("entity");

        while (entity != nullptr)
        {
            std::string name = entity->FindAttribute("name")->Value();

            // log the name of the entity so we know it was loaded
            std::cout << "Entity: " << name << std::endl;

            entityCount++;

            entity = entity->NextSiblingElement("entity");
        }

        return entityCount;
    }
}