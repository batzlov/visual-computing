#include <iostream>
#include <tinyxml2.h>
#include <string>
#include <sstream>
#include <algorithm>

#include "data.entitySystem.h"
#include "data.metaEntitySystem.h"
#include "data.playerSystem.h"

#include "../core/core.explode.h"

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

            auto positionFloatStrings = Core::Explode(
                xmlEntity
                ->FirstChildElement("data")
                ->FirstChildElement("position")
                ->FirstChild()
                ->Value(),
                ';'
            );
            auto sizeFloatStrings = Core::Explode(
				xmlEntity
				->FirstChildElement("data")
				->FirstChildElement("size")
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

            entity.size = Core::Float2(
				std::stof(sizeFloatStrings[0]),
				std::stof(sizeFloatStrings[1])
			);

            entity.aabb = Core::AABB2Float(
				Core::Float2(entity.position[0], entity.position[1]),
                Core::Float2(entity.position[0] + entity.size[0], entity.position[1] + entity.size[1])
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

    std::vector<Data::Entity*> EntitySystem::GetAll()
    {
        return itemManager.GetAll();
    }

    std::vector<Data::Entity*> EntitySystem::GetAllCollidables()
    {
		std::vector<Data::Entity*> collidables;
        std::vector<std::string> collidableNames = { "plattform_1", "plattform_2", "plattform_3"};

        for (auto& entity : itemManager.GetAll())
        {
            if (std::find(collidableNames.begin(), collidableNames.end(), entity->metaEntity->name) != collidableNames.end())
            {
				collidables.push_back(entity);
			}
		}

		return collidables;
	}
}