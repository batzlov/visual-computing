#include "game.startupPhase.h"

#include <iostream>
#include <tinyxml2.h>

#include "data/data.startupPhase.h"
#include "logic/logic.startupPhase.h"
#include "graphics/gfx.startupPhase.h"
#include "gui/gui.startupPhase.h"


namespace Game 
{
    int StartupPhase::InternOnEnter() 
    {
        std::cout << "Game - StartupPhase - InternOnEnter" << std::endl;

        Data::StartupPhase::GetInstance().OnEnter();
        Logic::StartupPhase::GetInstance().OnEnter();
        Gfx::StartupPhase::GetInstance().OnEnter();
        Gui::StartupPhase::GetInstance().OnEnter();

        std::cout << "Game - StartupPhase - InternOnEnter - Done" << std::endl;

        return 0;
    }

    int StartupPhase::InternOnRun() 
    {
        std::cout << "Game - StartupPhase - InternOnRun" << std::endl;

        tinyxml2::XMLDocument* document = new tinyxml2::XMLDocument();
        document->LoadFile("Y:\\visual-computing\\source\\ressources\\meta-entities.xml");

        Data::StartupPhase::GetInstance().OnRun(*document);
        Logic::StartupPhase::GetInstance().OnRun();
        Gfx::StartupPhase::GetInstance().OnRun();
        Gui::StartupPhase::GetInstance().OnRun();

        std::cout << "Game - StartupPhase - InternOnRun - Done" << std::endl;

        return Type::MAIN_MENU;
    }

    int StartupPhase::InternOnLeave() 
    {
        std::cout << "Game - StartupPhase - InternOnLeave" << std::endl;

        Data::StartupPhase::GetInstance().OnLeave();
        Logic::StartupPhase::GetInstance().OnLeave();
        Gfx::StartupPhase::GetInstance().OnLeave();
        Gui::StartupPhase::GetInstance().OnLeave();

        std::cout << "Game - StartupPhase - InternOnLeave - Done" << std::endl;
        
        return 0;
    }
}