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
        bgSprite.setScale(0.5, 0.5);
        bgSprite.setTexture(bgTexture);

        app.window.draw(bgSprite);
        

        // get all entities we need to draw
        std::vector<Data::Entity*> entities = Data::EntitySystem::GetInstance().GetAll();
        for(auto entity : entities) 
        {
            std::string filePath;
            sf::Texture entityTexture;
            sf::Sprite entitySprite;

            filePath = (Core::Config::ressourcesDir + "blocks\\block-brick.png").c_str();
            entityTexture.loadFromFile(filePath);

            entitySprite.setTexture(entityTexture);
            entitySprite.setScale(0.25, 0.25);
            entitySprite.setPosition(entity->position[0], entity->position[1]);

            app.window.draw(entitySprite);
        }

        app.window.display();
    }

    void PlayPhase::OnLeave() {}
}