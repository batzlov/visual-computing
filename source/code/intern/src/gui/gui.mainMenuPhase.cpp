#include "gui.mainMenuPhase.h"

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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
        {
            selectedMenuLabel = SelectedMenuLabel::PLAY;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
        {
            selectedMenuLabel = SelectedMenuLabel::EXIT;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && selectedMenuLabel == SelectedMenuLabel::PLAY)
        {
            return 1;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && selectedMenuLabel == SelectedMenuLabel::EXIT) 
        {
            return -1;
        }
        
        return 0;
    }

    void MainMenuPhase::OnLeave() {}

    SelectedMenuLabel MainMenuPhase::GetSelectedMenuLabel() 
    {
        return selectedMenuLabel;
    }
}