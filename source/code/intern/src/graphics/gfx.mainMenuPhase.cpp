#include <iostream>
#include <SFML/Graphics.hpp>

#include "gfx.mainMenuPhase.h"
#include "game/game.application.h"
#include "gui/gui.mainMenuPhase.h"

namespace Gfx
{
    void MainMenuPhase::Initialize() 
    {
        std::cout << "MainMenuPhase::Initialize()" << std::endl;

        Game::Application& app = Game::Application::GetInstance();

        // load textures
        textures[Gui::SelectedMenuLabel::PLAY].loadFromFile("Y:\\visual-computing\\source\\ressources\\screens\\main-menu-start.png");
        textures[Gui::SelectedMenuLabel::EXIT].loadFromFile("Y:\\visual-computing\\source\\ressources\\screens\\main-menu-exit.png");

        // apply textures to sprites
        screens[Gui::SelectedMenuLabel::PLAY].setTexture(textures[Gui::SelectedMenuLabel::PLAY]);
        screens[Gui::SelectedMenuLabel::PLAY].setScale(2, 2);
        screens[Gui::SelectedMenuLabel::EXIT].setTexture(textures[Gui::SelectedMenuLabel::EXIT]);
        screens[Gui::SelectedMenuLabel::EXIT].setScale(2, 2);
    }

    void MainMenuPhase::Render() 
    {
        Game::Application& app = Game::Application::GetInstance();
        auto selectLabel = Gui::MainMenuPhase::GetInstance().GetSelectedMenuLabel();

        app.window.clear(sf::Color::Black);
        app.window.draw(screens[selectLabel]);
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