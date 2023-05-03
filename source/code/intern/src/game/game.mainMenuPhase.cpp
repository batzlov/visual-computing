#include "game.mainMenuPhase.h"

#include <iostream>

#include "data/data.mainMenuPhase.h"
#include "graphics/gfx.mainMenuPhase.h"
#include "gui/gui.mainMenuPhase.h"

namespace Game 
{
    int MainMenuPhase::InternOnEnter() 
    {
        Data::MainMenuPhase::GetInstance().OnEnter();
        Gfx::MainMenuPhase::GetInstance().OnEnter();
        Gui::MainMenuPhase::GetInstance().OnEnter();

        return 0;
    }

    int MainMenuPhase::InternOnRun() 
    {
        Data::MainMenuPhase::GetInstance().OnRun();
        Gfx::MainMenuPhase::GetInstance().OnRun();
        int runState = Gui::MainMenuPhase::GetInstance().OnRun();


        if (runState == -1) 
        {
            return Type::SHUTDOWN;
        } 
        else if (runState == 1) 
        {
            return Type::LOAD_MAP;
        }

        return Type::MAIN_MENU;
    }

    int MainMenuPhase::InternOnLeave() 
    {
        Data::MainMenuPhase::GetInstance().OnLeave();
        Gfx::MainMenuPhase::GetInstance().OnLeave();
        Gui::MainMenuPhase::GetInstance().OnLeave();

        return 0;
    }
}