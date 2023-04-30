#include <iostream>

#include "data.loadPhase.h"

namespace Data 
{
    void LoadPhase::OnEnter() {}

    void LoadPhase::OnRun(tinyxml2::XMLDocument& document) 
    {
        std::cout << "LoadPhase::OnRun()" << std::endl;

        // we need a entity system that can load entities from xml
    }
    
    void LoadPhase::OnLeave() {}
}