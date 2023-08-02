#include <tinyxml2.h>

#include "data.startupPhase.h"
#include "data.metaEntitySystem.h"

namespace Data 
{
    void StartupPhase::OnEnter() {}

    void StartupPhase::OnRun(tinyxml2::XMLDocument& document) 
    {
        MetaEntitySystem::GetInstance().Initialize(document);
    }
    
    void StartupPhase::OnLeave() {}
}