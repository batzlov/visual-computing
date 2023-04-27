#include <iostream>
#include <SFML/Graphics/Text.hpp>

#include "gfx.mainMenuPhase.h"
#include "game/game.application.h"

namespace Gfx
{
    void MainMenuPhase::Initialize() 
    {
        std::cout << "MainMenuPhase::Initialize()" << std::endl;

        Game::Application& app = Game::Application::GetInstance();

        font.loadFromFile("amatic-sc-regular.ttf");
        // font.loadFromFile("X:\visual-computing\artists\fonts\amatic-sc-regular.ttf");

        introText.setFont(font);
        introText.setString("Hello World!");
        introText.setCharacterSize(60);
        introText.setFillColor(sf::Color::White);
    }

    void MainMenuPhase::Render() 
    {
        Game::Application& app = Game::Application::GetInstance();

        app.window.clear(sf::Color::Black);
        app.window.draw(introText);
        app.window.display();
    }

    void MainMenuPhase::OnEnter() 
    {
        Initialize();
    }

    void MainMenuPhase::OnRun() 
    {
        Render();
    }

    void MainMenuPhase::OnLeave() {}
}