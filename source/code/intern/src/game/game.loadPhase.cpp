#include "game.loadPhase.h"

#include <iostream>
#include <tinyxml2.h>

#include "data/data.loadPhase.h"
#include "logic/logic.loadPhase.h"
#include "graphics/gfx.loadPhase.h"
#include "gui/gui.loadPhase.h"

using namespace tinyxml2;
namespace Game 
{
    int LoadPhase::InternOnEnter() 
    {
        std::cout << "Game - LoadPhase - InternOnEnter" << std::endl;

        Data::LoadPhase::GetInstance().OnEnter();
        Logic::LoadPhase::GetInstance().OnEnter();
        Gfx::LoadPhase::GetInstance().OnEnter();
        Gui::LoadPhase::GetInstance().OnEnter();

        std::cout << "Game - LoadPhase - InternOnEnter - Done" << std::endl;

        return 0;
    }

    int LoadPhase::InternOnRun() 
    {
        std::cout << "Game - LoadPhase - InternOnRun" << std::endl;

        XMLDocument* document = new XMLDocument();
        document->LoadFile("Y:\\visual-computing\\source\\ressources\\levels\\level-1.xml");

        Data::LoadPhase::GetInstance().OnRun(*document);
        Logic::LoadPhase::GetInstance().OnRun();
        Gfx::LoadPhase::GetInstance().OnRun();
        Gui::LoadPhase::GetInstance().OnRun();

        std::cout << "Game - LoadPhase - InternOnRun - Done" << std::endl;

        return Type::PLAY;
    }

    int LoadPhase::InternOnLeave() 
    {
        std::cout << "Game - LoadPhase - InternOnLeave" << std::endl;

        Data::LoadPhase::GetInstance().OnLeave();
        Logic::LoadPhase::GetInstance().OnLeave();
        Gfx::LoadPhase::GetInstance().OnLeave();
        Gui::LoadPhase::GetInstance().OnLeave();

        std::cout << "Game - LoadPhase - InternOnLeave - Done" << std::endl;

        return 0;
    }
}