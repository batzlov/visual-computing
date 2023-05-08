#include "logic.playPhase.h"
#include "logic.system.h"

#include "../core/core.time.h"

namespace Logic 
{
    void PlayPhase::OnEnter() {}

    void PlayPhase::OnRun() 
    {
        if (Core::Time::GetTime() >= nextTurnTime)
        {
            nextTurnTime += turnInterval;

            System::GetInstance().OnTurn();
        }
    }

    void PlayPhase::OnLeave() {}
}