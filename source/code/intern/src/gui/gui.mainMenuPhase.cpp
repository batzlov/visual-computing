#include "gui.mainMenuPhase.h"

#include <SFML/Window/Keyboard.hpp>

namespace Gui 
{
    void MainMenuPhase::OnEnter() {}

    int MainMenuPhase::OnRun() 
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            return 1;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
        {
            return -1;
        }
        else 
        {
            return 0;
        }
    }
    
    void MainMenuPhase::OnLeave() {}
}