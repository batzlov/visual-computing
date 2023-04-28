#include <SFML/Graphics.hpp>

#include "gfx.loadPhase.h"
#include "game/game.application.h"

namespace Gfx 
{
    void LoadPhase::Initialize() 
    {
        texture.loadFromFile("Y:\\visual-computing\\source\\ressources\\screens\\loading-screen.png");
        screen.setTexture(texture);
        screen.setScale(2, 2);
    }

    void LoadPhase::Render() 
    {
        Game::Application& app = Game::Application::GetInstance();

        app.window.clear(sf::Color::Black);
        app.window.draw(screen);
        app.window.display();
    }

    void LoadPhase::OnEnter() 
    {
        Initialize();
    }

    void LoadPhase::OnRun() 
    {
        Render();
    }

    void LoadPhase::OnLeave() {}
}