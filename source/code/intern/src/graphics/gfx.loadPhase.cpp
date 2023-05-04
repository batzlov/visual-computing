#include <string>
#include <SFML/Graphics.hpp>

#include "gfx.loadPhase.h"
#include "core/core.config.h"
#include "game/game.application.h"

namespace Gfx 
{
    void LoadPhase::Initialize() 
    {
        std::string filePath = Core::Config::screensDir + "loading-screen.png";
        texture.loadFromFile(filePath.c_str());
        screen.setTexture(texture);
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