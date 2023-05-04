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

        tinyxml2::XMLElement* xmlEntities = document.FirstChildElement("entities");
        tinyxml2::XMLElement* xmlEntity = xmlEntities->FirstChildElement("entity");

        while (xmlEntity != nullptr)
        {
            std::string entityName = xmlEntity->FindAttribute("name")->Value();
            std::string metaEntityName = xmlEntity->FindAttribute("meta-entity")->Value();

            auto metaEntityId = metaEntitySystem.GetMetaEntityId(metaEntityName);
            Data::MetaEntity& metaEntity = metaEntitySystem.GetMetaEntityById(metaEntityId);

            auto entityId = idManager.Register(entityName);
            Entity& entity = itemManager.CreateItem(entityId);
            entity.metaEntity = &metaEntity;
            

            // log the name of the entity so we know it was loaded
            std::cout << "Entity: " << entityName << std::endl;
            std::cout << "Meta Entity: " << metaEntityName << std::endl;
            std::cout << "-------------------------------" << std::endl;

            entityCount++;

            xmlEntity = xmlEntity->NextSiblingElement("entity");
        }

        return entityCount;
    }

    std::vector<Data::Entity*> EntitySystem::GetAll()
    {
        return itemManager.GetAll();
    }
}