#include "data.mapSystem.h"

#include <tinyxml2.h>

namespace Data 
{
    MapSystem::MapSystem()
        : height(0.0f)
        , width(0.0f)
    {}

    float MapSystem::GetMapStart()
    {
        return 25.0f;
    }

    float MapSystem::GetMapEnd()
    {
        return this->width - 75.0f;
    }

    MapSystem::Initialize(tinyxml2::XMLDocument& document)
    {
        tinyxml2::XMLElement* xmlMap = document.FirstChildElement("map");

        this->height = std::stof(xmlMap->FirstChildElement("height")->Value());
        this->width = std::stof(xmlMap->FirstChildElement("width")->Value());
    }
}