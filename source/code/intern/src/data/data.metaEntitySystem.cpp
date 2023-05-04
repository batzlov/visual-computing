#include <iostream>

#include "data.metaEntitySystem.h"

namespace Data
{
    int MetaEntitySystem::Initialize(tinyxml2::XMLDocument& document)
    {
        int metaEntityCount = 0;

        tinyxml2::XMLElement* metaEntities = document.FirstChildElement("meta-entities");
        tinyxml2::XMLElement* metaEntity = metaEntities->FirstChildElement("meta-entity");

        while (metaEntity != nullptr)
        {
            std::string name = metaEntity->Attribute("name");

            MetaEntity& entity = itemManager.CreateItem(idManager.Register(name));
            entity.name = name;

            metaEntityCount++;

            metaEntity = metaEntity->NextSiblingElement("meta-entity");
        }

        return metaEntityCount;
    }

    Core::CIDManager::BID MetaEntitySystem::GetMetaEntityId(std::string name) 
    {
        return idManager.GetByName(name);
    }

    MetaEntity& MetaEntitySystem::GetMetaEntityById(Core::CIDManager::BID id) 
    {
        return itemManager.GetItem(id);
    }
}