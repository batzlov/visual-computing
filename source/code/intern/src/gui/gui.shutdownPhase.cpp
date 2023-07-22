#include "gui.shutdownPhase.h"
#include "gui.inputSystem.h"

#include "data/data.eventSystem.h"

namespace Gui 
{
    void ShutdownPhase::OnEnter() {}

    void ShutdownPhase::OnRun() {}

    void ShutdownPhase::OnLeave() 
    {
        Data::EventSystem::GetInstance().Unregister(Data::EventType::DispatchEventToInput,  &InputSystem::GetInstance().DispatchEventToInput);
    }
}