#include <iostream>
#include <tinyxml2.h>

#include "data.loadPhase.h"
#include "data.entitySystem.h"
#include "data.mapSystem.h"

namespace Data 
{
    void LoadPhase::OnEnter() {}

    void LoadPhase::OnRun(tinyxml2::XMLDocument& document) 
    {
        // store all relevant map data in the map system
        Data::MapSystem::GetInstance().Initialize(document);

        // we need a entity system that can load entities from xml
        Data::EntitySystem::GetInstance().Initialize(document);
    }
    
    void LoadPhase::OnLeave() {}
}