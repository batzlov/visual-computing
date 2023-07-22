#include "game.playPhase.h"

#include <iostream>

#include "core/core.time.h"
#include "game/game.application.h"
#include "data/data.eventSystem.h"
#include "graphics/gfx.playPhase.h"
#include "gui/gui.playPhase.h"
#include "logic/logic.playPhase.h"

namespace Game 
{
    PlayPhase::PlayPhase() 
        : nextRunPhase(Type::PLAY) {}

    int PlayPhase::InternOnEnter() 
    {   
        nextRunPhase = Type::PLAY;

        Core::Time::Reset();

        Data::EventSystem::GetInstance().Register(Data::EventType::FinishedMap, &PlayPhase::FinishedMap);
        Data::EventSystem::GetInstance().Register(Data::EventType::PressedEscape, &PlayPhase::Exit);

        Gfx::PlayPhase::GetInstance().OnEnter();
        Gui::PlayPhase::GetInstance().OnEnter();
        Logic::PlayPhase::GetInstance().OnEnter();

        return 0;
    }

    int PlayPhase::InternOnRun() 
    {
        Core::Time::OnFrame();

        Gfx::PlayPhase::GetInstance().OnRun();
        Gui::PlayPhase::GetInstance().OnRun();
        Logic::PlayPhase::GetInstance().OnRun();

        return Type::PLAY;
    }

    int PlayPhase::InternOnLeave() 
    {
        Data::EventSystem::GetInstance().Unregister(Data::EventType::FinishedMap, &PlayPhase::FinishedMap);
        Data::EventSystem::GetInstance().Unregister(Data::EventType::PressedEscape, &PlayPhase::Exit);

        Gfx::PlayPhase::GetInstance().OnLeave();
        Gui::PlayPhase::GetInstance().OnLeave();
        Logic::PlayPhase::GetInstance().OnLeave();

        return 0;
    }

    void PlayPhase::FinishedMap(Data::Event& /* event */)
    {
        PlayPhase::GetInstance().nextRunPhase = Type::UNLOAD_MAP;
    }

    void PlayPhase::Exit(Data::Event& /* event */)
    {
        PlayPhase::GetInstance().nextRunPhase = Type::UNLOAD_MAP;
    }
}