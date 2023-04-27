#include "game.playPhase.h"

#include <iostream>

#include "core/core_time.h"
#include "game/game.application.h"

#include "graphics/gfx.playPhase.h"
#include "gui/gui.playPhase.h"
#include "logic/logic.playPhase.h"

namespace Game 
{
    int PlayPhase::InternOnEnter() 
    {
        std::cout << "Game - PlayPhase - InternOnEnter" << std::endl;

        Gfx::PlayPhase::GetInstance().OnEnter();
        Gui::PlayPhase::GetInstance().OnEnter();
        Logic::PlayPhase::GetInstance().OnEnter();

        std::cout << "Game - PlayPhase - InternOnEnter - Done" << std::endl;

        return 0;
    }

    int PlayPhase::InternOnRun() 
    {
        std::cout << "Game - PlayPhase - InternOnRun" << std::endl;

        Gfx::PlayPhase::GetInstance().OnRun();
        Gui::PlayPhase::GetInstance().OnRun();
        Logic::PlayPhase::GetInstance().OnRun();

        std::cout << "Game - PlayPhase - InternOnRun - Done" << std::endl;

        return 0;
    }

    int PlayPhase::InternOnLeave() 
    {
        std::cout << "Game - PlayPhase - InternOnLeave" << std::endl;

        Gfx::PlayPhase::GetInstance().OnLeave();
        Gui::PlayPhase::GetInstance().OnLeave();
        Logic::PlayPhase::GetInstance().OnLeave();

        std::cout << "Game - PlayPhase - InternOnLeave - Done" << std::endl;

        return 0;
    }
}