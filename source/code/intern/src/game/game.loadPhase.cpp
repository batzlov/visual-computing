#include "game.loadPhase.h"

#include <iostream>
#include <string>
#include <tinyxml2.h>

#include "core/core.config.h"
#include "data/data.loadPhase.h"
#include "logic/logic.loadPhase.h"
#include "graphics/gfx.loadPhase.h"
#include "gui/gui.loadPhase.h"

using namespace tinyxml2;
namespace Game 
{
    int LoadPhase::InternOnEnter() 
    {
        Data::LoadPhase::GetInstance().OnEnter();
        Logic::LoadPhase::GetInstance().OnEnter();
        Gfx::LoadPhase::GetInstance().OnEnter();
        Gui::LoadPhase::GetInstance().OnEnter();

        return 0;
    }

    int LoadPhase::InternOnRun() 
    {

        XMLDocument* document = new XMLDocument();
        // std::string filePath = Core::Config::levelsDir + "level-1.xml";
        std::string filePath = Core::Config::levelsDir + "level-experimental-1.xml";
        document->LoadFile(filePath.c_str());

        Data::LoadPhase::GetInstance().OnRun(*document);
        Logic::LoadPhase::GetInstance().OnRun();
        Gfx::LoadPhase::GetInstance().OnRun();
        Gui::LoadPhase::GetInstance().OnRun();

        return Type::PLAY;
    }

    int LoadPhase::InternOnLeave() 
    {
        Data::LoadPhase::GetInstance().OnLeave();
        Logic::LoadPhase::GetInstance().OnLeave();
        Gfx::LoadPhase::GetInstance().OnLeave();
        Gui::LoadPhase::GetInstance().OnLeave();

        return 0;
    }
}