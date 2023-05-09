#include <iostream>
#include <SFML/Graphics.hpp>

#include "gfx.startupPhase.h"
#include "core/core.config.h"
#include "data/data.metaEntitySystem.h"

namespace Gfx
{
    void StartupPhase::OnEnter() {}

    void StartupPhase::OnRun(tinyxml2::XMLDocument& document) 
    {
        Data::MetaEntitySystem& metaEntitySystem = Data::MetaEntitySystem::GetInstance();

        tinyxml2::XMLElement* xmlMetaEntities = document.FirstChildElement("meta-entities");
        tinyxml2::XMLElement* xmlMetaEntity = xmlMetaEntities->FirstChildElement("meta-entity");

        while(xmlMetaEntity != nullptr) 
        {
            auto metaEntityId = metaEntitySystem.GetMetaEntityId(
                xmlMetaEntity
                    ->FindAttribute("name")
                    ->Value()
            );
            Data::MetaEntity& metaEntity = metaEntitySystem.GetMetaEntityById(metaEntityId);

            // get a pointer to the belonging texture
            tinyxml2::XMLElement* xmlGraphicsElement = xmlMetaEntity->FirstChildElement("graphics");
            std::string textureName = xmlGraphicsElement->FirstChildElement("texture")->FindAttribute("value")->Value();
            std::string filePath = (Core::Config::texturesDir + textureName).c_str();
            
            sf::Texture* texture = new sf::Texture();
            if(texture->loadFromFile(filePath)) 
            {
                metaEntity.facets[0] = texture;
            }

            xmlMetaEntity = xmlMetaEntity->NextSiblingElement("meta-entity");
        }
    }

    void StartupPhase::OnLeave() {}
}