#include <iostream>
#include <SFML/Graphics.hpp>

#include "gfx.playPhase.h"
#include "core/core.config.h"
#include "game/game.application.h";
#include "data/data.entity.h"
#include "data/data.entitySystem.h"

namespace Gfx
{
    void PlayPhase::OnEnter() {}

    void PlayPhase::OnRun() 
    {
        Game::Application& app = Game::Application::GetInstance();

        // TODO: clear the window and draw the background image, next we need to get all entities and draw them on the screen
        app.window.clear(sf::Color::Black);

        std::string filePath = Core::Config::backgroundDirs + "beach.jpg";
        sf::Texture bgTexture;
        bgTexture.loadFromFile(filePath.c_str());

        sf::Sprite bgSprite;
        bgSprite.setTexture(bgTexture);

        app.window.draw(bgSprite);
        

        // get all entities we need to draw
        std::vector<Data::Entity*> entities = Data::EntitySystem::GetInstance().GetAll();
        for(auto entity : entities) 
        {
            // draw the entities
        }

        app.window.display();
    }

    void PlayPhase::OnLeave() {}
}