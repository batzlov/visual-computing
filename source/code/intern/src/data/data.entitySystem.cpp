#include <iostream>
#include <tinyxml2.h>
#include <string>
#include <sstream>

#include "data.entitySystem.h"
#include "data.metaEntitySystem.h"
#include "data.playerSystem.h"

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

            auto positionFloatStrings = this->Explode(
                xmlEntity
                ->FirstChildElement("data")
                ->FirstChildElement("position")
                ->FirstChild()
                ->Value(),
                ';'
            );

            auto entityId = idManager.Register(entityName);
            Entity& entity = itemManager.CreateItem(entityId);
            entity.metaEntity = &metaEntity;
            entity.position = Core::Float2(
                std::stof(positionFloatStrings[0]),
                std::stof(positionFloatStrings[1])
            );

            // handle the player entity seperately
            if (entity.metaEntity->name == "player")
            {
                Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
                playerSystem.SetPlayer(&entity);
            }

            entityCount++;

            xmlEntity = xmlEntity->NextSiblingElement("entity");
        }

        return entityCount;
    }

    std::vector<std::string> EntitySystem::Explode(std::string string, const char& delimiter) 
    {
        std::string tmpSubString;
        std::stringstream ss(string);
        std::vector<std::string> subStrings;

        while (getline(ss, tmpSubString, delimiter))
        {
            subStrings.push_back(tmpSubString);
        }

        return subStrings;
    }

    std::vector<Data::Entity*> EntitySystem::GetAll()
    {
        return itemManager.GetAll();
    }
}