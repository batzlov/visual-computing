#include "game.unloadPhase.h"

#include <iostream>

#include "logic/logic.unloadPhase.h"
#include "graphics/gfx.unloadPhase.h"
#include "gui/gui.unloadPhase.h"


namespace Game 
{
    int UnloadPhase::InternOnEnter() 
    {
        std::cout << "Game - UnloadPhase - InternOnEnter" << std::endl;

        Logic::UnloadPhase::GetInstance().OnEnter();
        Gfx::UnloadPhase::GetInstance().OnEnter();
        Gui::UnloadPhase::GetInstance().OnEnter();

        std::cout << "Game - UnloadPhase - InternOnEnter - Done" << std::endl;

        return 0;
    }

    int UnloadPhase::InternOnRun() 
    {
        std::cout << "Game - UnloadPhase - InternOnRun" << std::endl;

        Logic::UnloadPhase::GetInstance().OnRun();
        Gfx::UnloadPhase::GetInstance().OnRun();
        Gui::UnloadPhase::GetInstance().OnRun();

        std::cout << "Game - UnloadPhase - InternOnRun - Done" << std::endl;
    }

    int UnloadPhase::InternOnLeave() 
    {
        std::cout << "Game - UnloadPhase - InternOnLeave" << std::endl;

        Logic::UnloadPhase::GetInstance().OnLeave();
        Gfx::UnloadPhase::GetInstance().OnLeave();
        Gui::UnloadPhase::GetInstance().OnLeave();

        std::cout << "Game - UnloadPhase - InternOnLeave - Done" << std::endl;
    }
}