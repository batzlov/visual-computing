#include "game.shutdownPhase.h"

#include <iostream>

#include "data/data.shutdownPhase.h"
#include "logic/logic.shutdownPhase.h"
#include "graphics/gfx.shutdownPhase.h"
#include "gui/gui.shutdownPhase.h"

namespace Game 
{
    int ShutdownPhase::InternOnEnter()
    {
        Data::ShutdownPhase::GetInstance().OnEnter();
        Logic::ShutdownPhase::GetInstance().OnEnter();
        Gfx::ShutdownPhase::GetInstance().OnEnter();
        Gui::ShutdownPhase::GetInstance().OnEnter();

        return 0;
    }

    int ShutdownPhase::InternOnRun()
    {
        Data::ShutdownPhase::GetInstance().OnRun();
        Logic::ShutdownPhase::GetInstance().OnRun();
        Gfx::ShutdownPhase::GetInstance().OnRun();
        Gui::ShutdownPhase::GetInstance().OnRun();

        return Type::Undefined;
    }

    int ShutdownPhase::InternOnLeave()
    {
        Data::ShutdownPhase::GetInstance().OnLeave();
        Logic::ShutdownPhase::GetInstance().OnLeave();
        Gfx::ShutdownPhase::GetInstance().OnLeave();
        Gui::ShutdownPhase::GetInstance().OnLeave();

        return 0;
    }
}