#include <iostream>
#include <tinyxml2.h>

#include "data.loadPhase.h"
#include "data.entitySystem.h"

namespace Data 
{
    void LoadPhase::OnEnter() {}

    void LoadPhase::OnRun(tinyxml2::XMLDocument& document) 
    {
        // we need a entity system that can load entities from xml
        Data::EntitySystem::GetInstance().Initialize(document);
    }
    
    void LoadPhase::OnLeave() {}
}