#include "game.playPhase.h"

#include <iostream>

#include "core/core.time.h"
#include "game/game.application.h"

#include "graphics/gfx.playPhase.h"
#include "gui/gui.playPhase.h"
#include "logic/logic.playPhase.h"

namespace Game 
{
    int PlayPhase::InternOnEnter() 
    {
        Core::Time::Reset();

        Gfx::PlayPhase::GetInstance().OnEnter();
        Gui::PlayPhase::GetInstance().OnEnter();
        Logic::PlayPhase::GetInstance().OnEnter();

        return 0;
    }

    int PlayPhase::InternOnRun() 
    {
        Core::Time::OnFrame();

        Gfx::PlayPhase::GetInstance().OnRun();
        Gui::PlayPhase::GetInstance().OnRun();
        Logic::PlayPhase::GetInstance().OnRun();

        return Type::PLAY;
    }

    int PlayPhase::InternOnLeave() 
    {
        Gfx::PlayPhase::GetInstance().OnLeave();
        Gui::PlayPhase::GetInstance().OnLeave();
        Logic::PlayPhase::GetInstance().OnLeave();

        return 0;
    }
}