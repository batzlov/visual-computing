#include "gui.mainMenuPhase.h"
#include "gui.inputSystem.h"

#include "data/data.eventType.h"
#include "data/data.eventSystem.h"

#include <SFML/Window/Keyboard.hpp>

namespace Gui 
{
    MainMenuPhase::MainMenuPhase() 
        : selectedMenuLabel(SelectedMenuLabel::PLAY)
        , enterPressed(false)
        , escapePressed(false) {}

    void MainMenuPhase::OnEnter() {}

    int MainMenuPhase::OnRun() 
    {
        InputSystem::GetInstance().OnRun();
        
        return 0;
    }

    void MainMenuPhase::OnLeave() {}

    SelectedMenuLabel MainMenuPhase::GetSelectedMenuLabel() 
    {
        return selectedMenuLabel;
    }

    void MainMenuPhase::SetSelectedMenuLabel(SelectedMenuLabel selectedMenuLabel)
    {
		this->selectedMenuLabel = selectedMenuLabel;
	}
}