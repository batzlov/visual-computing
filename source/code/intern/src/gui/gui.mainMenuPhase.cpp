#include <iostream>

#include "gui.mainMenuPhase.h"
#include "gui.inputSystem.h"

#include "core/core.time.h"
#include "data/data.eventType.h"
#include "data/data.eventSystem.h"

#include <SFML/Window/Keyboard.hpp>

namespace Gui 
{
    MainMenuPhase::MainMenuPhase() 
        : selectedMenuLabel(SelectedMenuLabel::PLAY)
        , enterPressed(false)
        , escapePressed(false)
        , indicateLevelChange(false) 
        , indicateLevelChangeDuration(2)
    {}

    void MainMenuPhase::OnEnter() {}

    int MainMenuPhase::OnRun() 
    {
        InputSystem::GetInstance().OnRun();
        
        return 0;
    }

    void MainMenuPhase::OnLeave() {}

    int MainMenuPhase::GetSelectedLevel() const
    {
        return selectedLevel;
    }

    void MainMenuPhase::SetSelectedLevel(int level)
    {
        selectedLevel = level;
    }

    bool MainMenuPhase::IndicateLevelChange()
    {
        bool indicationDurationPassed = this->indicateLevelChangeTimer.getElapsedTime().asSeconds() > indicateLevelChangeDuration;
        if(indicateLevelChange && !indicationDurationPassed)
        {
            return true;
        }

        return false;
    }

    void MainMenuPhase::SetIndicateLevelChange(bool indicateLevelChange)
    {
        this->indicateLevelChange = indicateLevelChange;
        this->indicateLevelChangeTimer.restart();
    }

    SelectedMenuLabel MainMenuPhase::GetSelectedMenuLabel() 
    {
        return selectedMenuLabel;
    }

    void MainMenuPhase::SetSelectedMenuLabel(SelectedMenuLabel selectedMenuLabel)
    {
		this->selectedMenuLabel = selectedMenuLabel;
	}
}