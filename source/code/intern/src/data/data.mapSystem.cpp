#include "data.mapSystem.h"

#include <iostream>
#include <string>

namespace Data 
{
    MapSystem::MapSystem()
        : height(0.0f)
        , width(0.0f)
    {}

    float MapSystem::GetHeight()
    {
		return this->height;
	}

    float MapSystem::GetWidth()
    {
        return this->width;
    }

    float MapSystem::GetMapStart()
    {
        return 25.0f;
    }

    float MapSystem::GetMapEnd()
    {
        return this->width - 75.0f;
    }

    float MapSystem::GetViewBorderStart()
    {
		return 150.0f;
	}

    float MapSystem::GetViewBorderEnd()
    {
        return this->width - 650.0f;
    }

    void MapSystem::Initialize(tinyxml2::XMLDocument& document)
    {
        tinyxml2::XMLElement* xmlMap = document.RootElement();

        this->height = std::stof(xmlMap->FirstChildElement("height")->GetText());
        this->width = std::stof(xmlMap->FirstChildElement("width")->GetText());
    }
}