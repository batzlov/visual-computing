#include "game.mainMenuPhase.h"

#include <iostream>

#include "data/data.mainMenuPhase.h"
#include "data/data.eventSystem.h"
#include "data/data.levelSystem.h"
#include "graphics/gfx.mainMenuPhase.h"
#include "gui/gui.mainMenuPhase.h"

namespace Game 
{
    int MainMenuPhase::InternOnEnter() 
    {
        nextRunPhase = Type::MAIN_MENU;

        Data::EventSystem::GetInstance().Register(Data::EventType::PressedEnter, &MainMenuPhase::OnEnter);
        Data::EventSystem::GetInstance().Register(Data::EventType::PressedEscape, &MainMenuPhase::OnExit);
        Data::EventSystem::GetInstance().Register(Data::EventType::PressedUp, &MainMenuPhase::OnUp);
        Data::EventSystem::GetInstance().Register(Data::EventType::PressedDown, &MainMenuPhase::OnDown);
        Data::EventSystem::GetInstance().Register(Data::EventType::PressedOne, &MainMenuPhase::OnOne);
        Data::EventSystem::GetInstance().Register(Data::EventType::PressedTwo, &MainMenuPhase::OnTwo);

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
        Data::EventSystem::GetInstance().Unregister(Data::EventType::PressedEnter, &MainMenuPhase::OnEnter);
        Data::EventSystem::GetInstance().Unregister(Data::EventType::PressedEscape, &MainMenuPhase::OnExit);
        Data::EventSystem::GetInstance().Unregister(Data::EventType::PressedUp, &MainMenuPhase::OnUp);
        Data::EventSystem::GetInstance().Unregister(Data::EventType::PressedDown, &MainMenuPhase::OnDown);
        Data::EventSystem::GetInstance().Unregister(Data::EventType::PressedOne, &MainMenuPhase::OnOne);
		Data::EventSystem::GetInstance().Unregister(Data::EventType::PressedTwo, &MainMenuPhase::OnTwo);

        Data::MainMenuPhase::GetInstance().OnLeave();
        Gfx::MainMenuPhase::GetInstance().OnLeave();
        Gui::MainMenuPhase::GetInstance().OnLeave();

        return 0;
    }

    void MainMenuPhase::OnStart(Data::Event& /* event */)
    {
        MainMenuPhase::GetInstance().nextRunPhase = Phase::LOAD_MAP;
    }

    void MainMenuPhase::OnEnter(Data::Event& /* event */)
    {
        Gui::SelectedMenuLabel selectedLabel = Gui::MainMenuPhase::GetInstance().GetSelectedMenuLabel();
        
        if(selectedLabel == Gui::SelectedMenuLabel::PLAY) 
        {
            MainMenuPhase::GetInstance().nextRunPhase = Phase::LOAD_MAP;
        }
        else if (selectedLabel == Gui::SelectedMenuLabel::EXIT)
        {
			MainMenuPhase::GetInstance().nextRunPhase = Phase::SHUTDOWN;
		}
	}

    void MainMenuPhase::OnUp(Data::Event& /* event */)
    {
        Gui::MainMenuPhase::GetInstance().SetSelectedMenuLabel(Gui::SelectedMenuLabel::PLAY);
	}

    void MainMenuPhase::OnDown(Data::Event& /* event */)
    {
		Gui::MainMenuPhase::GetInstance().SetSelectedMenuLabel(Gui::SelectedMenuLabel::EXIT);
    }

    void MainMenuPhase::OnExit(Data::Event& /* event */)
    {
        MainMenuPhase::GetInstance().nextRunPhase = Phase::SHUTDOWN;
    }

    void MainMenuPhase::OnOne(Data::Event& /* event */)
    {
        std::cout << "1" << std::endl;

        Data::LevelSystem::GetInstance().SetSelectedLevel(1);
        
        Gui::MainMenuPhase::GetInstance().SetIndicateLevelChange(true);
    }

    void MainMenuPhase::OnTwo(Data::Event& /* event */)
    {
        std::cout << "2" << std::endl;

        Data::LevelSystem::GetInstance().SetSelectedLevel(2);

        Gui::MainMenuPhase::GetInstance().SetIndicateLevelChange(true);
    }
}