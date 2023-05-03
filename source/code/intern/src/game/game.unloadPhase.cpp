#include "game.unloadPhase.h"

#include <iostream>

#include "logic/logic.unloadPhase.h"
#include "graphics/gfx.unloadPhase.h"
#include "gui/gui.unloadPhase.h"


namespace Game 
{
    int UnloadPhase::InternOnEnter() 
    {
        Logic::UnloadPhase::GetInstance().OnEnter();
        Gfx::UnloadPhase::GetInstance().OnEnter();
        Gui::UnloadPhase::GetInstance().OnEnter();


        return 0;
    }

    int UnloadPhase::InternOnRun() 
    {
        Logic::UnloadPhase::GetInstance().OnRun();
        Gfx::UnloadPhase::GetInstance().OnRun();
        Gui::UnloadPhase::GetInstance().OnRun();

        return Type::MAIN_MENU;
    }

    int UnloadPhase::InternOnLeave() 
    {
        Logic::UnloadPhase::GetInstance().OnLeave();
        Gfx::UnloadPhase::GetInstance().OnLeave();
        Gui::UnloadPhase::GetInstance().OnLeave();

        return 0;
    }
}