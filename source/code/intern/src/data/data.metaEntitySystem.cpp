#include <iostream>

#include "data.metaEntitySystem.h"

#include "../core/core.explode.h"
#include "../core/core.aabb.h"

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

            tinyxml2::XMLElement* dataElement = metaEntity->FirstChildElement("data");

            float size = dataElement->FirstChildElement("size")->FloatAttribute("value");

            auto minCornerStrings = Core::Explode(dataElement->FirstChildElement("aabb")->Attribute("minCorner"), ';');
            auto maxCornerStrings = Core::Explode(dataElement->FirstChildElement("aabb")->Attribute("maxCorner"), ';');
            
            Core::AABB2Float aabb = Core::AABB2Float(
                Core::Float2(
                    std::stof(minCornerStrings[0]),
                    std::stof(minCornerStrings[1])
                ),
                Core::Float2(
                    std::stof(maxCornerStrings[0]),
                    std::stof(maxCornerStrings[1])
                )
            );

            MetaEntity& entity = itemManager.CreateItem(idManager.Register(name));
            entity.name = name;
            entity.size = size;
            entity.aabb = aabb;

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