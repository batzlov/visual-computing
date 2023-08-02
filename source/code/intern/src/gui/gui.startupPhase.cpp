#include "gui.startupPhase.h"
#include "gui.inputSystem.h"

#include "data/data.eventSystem.h"


namespace Gui 
{
    void StartupPhase::OnEnter() 
    {
        Data::EventSystem::GetInstance().Register(
            Data::EventType::DispatchEventToInput,  
            &InputSystem::GetInstance().DispatchEventToInput
        );
    }

    void StartupPhase::OnRun() {}
    
    void StartupPhase::OnLeave() {}
}