#include <tinyxml2.cpp>

#include "data.startupPhase.h"
#include "data.metaEntitySystem.h"

namespace Data 
{
    void StartupPhase::OnEnter() {}

    void StartupPhase::OnRun(tinyxml2::XMLDocument& document) 
    {
        int metaEntityCount = MetaEntitySystem::GetInstance().Initialize(document);
    }
    
    void StartupPhase::OnLeave() {}
}