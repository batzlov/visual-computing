#include "game.mainMenuPhase.h"

#include <iostream>

#include "data/data.mainMenuPhase.h"
#include "graphics/gfx.mainMenuPhase.h"
#include "gui/gui.mainMenuPhase.h"

namespace Game 
{
    int MainMenuPhase::InternOnEnter() 
    {
        std::cout << "Game - MainMenuPhase - InternOnEnter" << std::endl;

        Data::MainMenuPhase::GetInstance().OnEnter();
        Gfx::MainMenuPhase::GetInstance().OnEnter();
        Gui::MainMenuPhase::GetInstance().OnEnter();

        std::cout << "Game - MainMenuPhase - InternOnEnter - Done" << std::endl;

        return 0;
    }

    int MainMenuPhase::InternOnRun() 
    {
        std::cout << "Game - MainMenuPhase - InternOnRun" << std::endl;

        Data::MainMenuPhase::GetInstance().OnRun();
        Gfx::MainMenuPhase::GetInstance().OnRun();
        Gui::MainMenuPhase::GetInstance().OnRun();

        std::cout << "Game - MainMenuPhase - InternOnRun - Done" << std::endl;

        return 0;
    }

    int MainMenuPhase::InternOnLeave() 
    {
        std::cout << "Game - MainMenuPhase - InternOnLeave" << std::endl;

        Data::MainMenuPhase::GetInstance().OnLeave();
        Gfx::MainMenuPhase::GetInstance().OnLeave();
        Gui::MainMenuPhase::GetInstance().OnLeave();

        std::cout << "Game - MainMenuPhase - InternOnLeave - Done" << std::endl;

        return 0;
    }
}