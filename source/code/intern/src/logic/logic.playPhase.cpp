#include "logic.playPhase.h"
#include "logic.system.h"
#include "logic.commandSystem.h"

#include "../core/core.time.h"
#include "../data/data.eventSystem.h"

namespace Logic 
{
    void PlayPhase::OnEnter() 
    {
        Data::EventSystem::GetInstance().Register(Data::EventType::DispatchInputToCommand, &CommandSystem::DispatchInputToLogic);
    }

    void PlayPhase::OnRun() 
    {
        if (Core::Time::GetTime() >= nextTurnTime)
        {
            nextTurnTime += turnInterval;

            System::GetInstance().OnTurn();
        }
    }

    void PlayPhase::OnLeave() 
    {
        Data::EventSystem::GetInstance().Unregister(Data::EventType::DispatchInputToCommand, &CommandSystem::DispatchInputToLogic);

        nextTurnTime = 0.0;
    }
}