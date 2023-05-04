#include "game.startupPhase.h"

#include <iostream>
#include <string>
#include <tinyxml2.h>

#include "core/core.config.h"
#include "data/data.startupPhase.h"
#include "logic/logic.startupPhase.h"
#include "graphics/gfx.startupPhase.h"
#include "gui/gui.startupPhase.h"


namespace Game 
{
    int StartupPhase::InternOnEnter() 
    {
        Data::StartupPhase::GetInstance().OnEnter();
        Logic::StartupPhase::GetInstance().OnEnter();
        Gfx::StartupPhase::GetInstance().OnEnter();
        Gui::StartupPhase::GetInstance().OnEnter();

        return 0;
    }

    int StartupPhase::InternOnRun() 
    {
        tinyxml2::XMLDocument* document = new tinyxml2::XMLDocument();
        const std::string filePath = Core::Config::ressourcesDir + "meta-entities.xml";
        document->LoadFile(filePath.c_str());

        Data::StartupPhase::GetInstance().OnRun(*document);
        Logic::StartupPhase::GetInstance().OnRun();
        Gfx::StartupPhase::GetInstance().OnRun(*document);
        Gui::StartupPhase::GetInstance().OnRun();

        return Type::MAIN_MENU;
    }

    int StartupPhase::InternOnLeave() 
    {
        Data::StartupPhase::GetInstance().OnLeave();
        Logic::StartupPhase::GetInstance().OnLeave();
        Gfx::StartupPhase::GetInstance().OnLeave();
        Gui::StartupPhase::GetInstance().OnLeave();
        
        return 0;
    }
}