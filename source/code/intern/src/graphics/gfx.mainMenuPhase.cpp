#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "core/core.config.h"
#include "gfx.mainMenuPhase.h"
#include "game/game.application.h"
#include "gui/gui.mainMenuPhase.h"
#include "data/data.levelSystem.h"

namespace Gfx
{
    void MainMenuPhase::Initialize() 
    {
        Game::Application& app = Game::Application::GetInstance();

        std::string filePath;

        // load textures
        filePath = Core::Config::screensDir + "main-menu-start.png";
        textures[Gui::SelectedMenuLabel::PLAY].loadFromFile(filePath.c_str());

        filePath = Core::Config::screensDir + "main-menu-exit.png";
        textures[Gui::SelectedMenuLabel::EXIT].loadFromFile(filePath.c_str());

        // apply textures to sprites
        screens[Gui::SelectedMenuLabel::PLAY].setTexture(textures[Gui::SelectedMenuLabel::PLAY]);
        screens[Gui::SelectedMenuLabel::EXIT].setTexture(textures[Gui::SelectedMenuLabel::EXIT]);
    }

    void MainMenuPhase::Render() 
    {
        Game::Application& app = Game::Application::GetInstance();
        auto selectLabel = Gui::MainMenuPhase::GetInstance().GetSelectedMenuLabel();

        bool indicateLevelChange = Gui::MainMenuPhase::GetInstance().IndicateLevelChange();
        if(indicateLevelChange)
        {
            app.window.setView(app.window.getDefaultView());
            app.window.clear(sf::Color(49, 196, 177));

            sf::Font font;
            font.loadFromFile(Core::Config::fontsDir + "amatic-sc-bold.ttf");
                                   
            sf::Text text;
            std::string levelText = "Selected Level: " + std::to_string(Data::LevelSystem::GetInstance().GetSelectedLevel());
            text.setString(levelText);
            text.setFont(font);
            text.setCharacterSize(50);
            text.setFillColor(sf::Color::Black);

            // set position to center of the screen
            sf::Vector2f viewCenter = app.window.getView().getCenter();
            viewCenter.x = viewCenter.x - text.getLocalBounds().width / 2;
            viewCenter.y = viewCenter.y - text.getLocalBounds().height;
            text.setPosition(viewCenter);

            app.window.draw(text);
            app.window.display();
        }
        else
        {
            // reset view
            app.window.setView(app.window.getDefaultView());
            app.window.clear(sf::Color::Black);
            app.window.draw(screens[selectLabel]);
            app.window.display();
        }
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