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

        Data::EventSystem::GetInstance().Register(Data::EventType::PressedEnter, &MainMenuPhase::OnEnter);
        Data::EventSystem::GetInstance().Register(Data::EventType::PressedEscape, &MainMenuPhase::OnExit);
        Data::EventSystem::GetInstance().Register(Data::EventType::PressedUp, &MainMenuPhase::OnUpOrDown);
        Data::EventSystem::GetInstance().Register(Data::EventType::PressedDown, &MainMenuPhase::OnUpOrDown);

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
        Data::EventSystem::GetInstance().Unregister(Data::EventType::PressedUp, &MainMenuPhase::OnUpOrDown);
        Data::EventSystem::GetInstance().Unregister(Data::EventType::PressedDown, &MainMenuPhase::OnUpOrDown);

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

    void MainMenuPhase::OnUpOrDown(Data::Event& /* event */)
    {
        auto selectedLabel = Gui::MainMenuPhase::GetInstance().GetSelectedMenuLabel();

        if (selectedLabel == Gui::SelectedMenuLabel::PLAY)
        {
			Gui::MainMenuPhase::GetInstance().SetSelectedMenuLabel(Gui::SelectedMenuLabel::EXIT);
		}
        else if (selectedLabel == Gui::SelectedMenuLabel::EXIT)
        {
			Gui::MainMenuPhase::GetInstance().SetSelectedMenuLabel(Gui::SelectedMenuLabel::PLAY);
		}
	}

    void MainMenuPhase::OnExit(Data::Event& /* event */)
    {
        MainMenuPhase::GetInstance().nextRunPhase = Phase::SHUTDOWN;
    }
}