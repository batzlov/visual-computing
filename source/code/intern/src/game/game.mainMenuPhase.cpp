#include "game.mainMenuPhase.h"

#include <iostream>

#include "data/data.mainMenuPhase.h"
#include "data/data.eventSystem.h"
#include "graphics/gfx.mainMenuPhase.h"
#include "gui/gui.mainMenuPhase.h"

namespace Game 
{
    int MainMenuPhase::InternOnEnter() 
    {
        nextRunPhase = Type::MAIN_MENU;

        Data::EventSystem::GetInstance().Register(Data::EventType::PressedEnter, &MainMenuPhase::OnStart);
        Data::EventSystem::GetInstance().Register(Data::EventType::PressedEscape, &MainMenuPhase::OnExit);

        Data::MainMenuPhase::GetInstance().OnEnter();
        Gfx::MainMenuPhase::GetInstance().OnEnter();
        Gui::MainMenuPhase::GetInstance().OnEnter();

        return 0;
    }

    int MainMenuPhase::InternOnRun() 
    {
        Data::MainMenuPhase::GetInstance().OnRun();
        Gfx::MainMenuPhase::GetInstance().OnRun();
        Gui::MainMenuPhase::GetInstance().OnRun();

        return nextRunPhase;
    }

    int MainMenuPhase::InternOnLeave() 
    {
        Data::EventSystem::GetInstance().Unregister(Data::EventType::PressedEnter, &MainMenuPhase::OnStart);
        Data::EventSystem::GetInstance().Unregister(Data::EventType::PressedEscape, &MainMenuPhase::OnExit);

        Data::MainMenuPhase::GetInstance().OnLeave();
        Gfx::MainMenuPhase::GetInstance().OnLeave();
        Gui::MainMenuPhase::GetInstance().OnLeave();

        return 0;
    }

    void MainMenuPhase::OnStart(Data::Event& /* event */)
    {
        std::cout << "Enter pressed" << std::endl;
        MainMenuPhase::GetInstance().nextRunPhase = Phase::LOAD_MAP;
    }

    void MainMenuPhase::OnExit(Data::Event& /* event */)
    {
        MainMenuPhase::GetInstance().nextRunPhase = Phase::SHUTDOWN;
    }
}