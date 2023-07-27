#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "gfx.playPhase.h"
#include "core/core.config.h"
#include "game/game.application.h"
#include "data/data.entity.h"
#include "data/data.entitySystem.h"
#include "data/data.playerSystem.h"

namespace Gfx
{
    void PlayPhase::OnEnter() {}

    void PlayPhase::OnRun() 
    {
        Game::Application& app = Game::Application::GetInstance();

        // TODO: clear the window and draw the background image, next we need to get all entities and draw them on the screen
        app.window.clear(sf::Color::Black);

        std::string filePath = Core::Config::backgroundDirs + "background.png";
        sf::Texture bgTexture;
        bgTexture.loadFromFile(filePath.c_str());
        bgTexture.setRepeated(true);
        
        sf::IntRect bounds(0, 0, 1600, 1600);
        sf::Sprite bgSprite = sf::Sprite(bgTexture, bounds);
        bgSprite.setPosition(
            (float) bounds.left, 
            (float) bounds.top - 700.0f + app.GetInstance().window.getView().getSize().y
        );

        app.window.draw(bgSprite);
        
        // get all entities we need to draw
        std::vector<Data::Entity*> entities = Data::EntitySystem::GetInstance().GetAll();
        Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
        for(auto entity : entities) 
        {
            std::string filePath;
            sf::Texture* entityTexture;
            sf::Sprite entitySprite;

            entityTexture = static_cast<sf::Texture*>(entity->metaEntity->facets[0]);

            entitySprite.setTexture(*entityTexture);
            entitySprite.setPosition(entity->position[0], entity->position[1]);

            // FIXME: error
            bool changePlayerDirection = false;
            if (changePlayerDirection)
            {
                if (entity->metaEntity->name == "player" && !playerSystem.GetLooksRight())
                {
                    entitySprite.setOrigin({ 0, 0 });
                    entitySprite.setScale(-1, 1);
                }
                else if (entity->metaEntity->name == "player" && playerSystem.GetLooksRight())
                {
                    entitySprite.setOrigin({ 0, 0 });
                    entitySprite.setScale(1, 1);
                }
            }

            app.window.draw(entitySprite);

            // update the view position and background position to follow the player
            if (entity->metaEntity->name == "player")
            {
                float minBorderX = 150;
                float maxBorderX = 950;

                // if the player is moving out of the screen, then don't need to move the view
                if (entity->position[0] < minBorderX || entity->position[0] > maxBorderX)
                {
                    continue;
                }

                // FIXME: check if the player distance to the right or left border is less than 100px, then move the view
                sf::View view = app.window.getView();
               
                float centerX = entity->position[0] + 250;
                float centerY = view.getCenter().y;
                // float centerY = entity->position[1] - 150;

                view.setCenter(centerX, centerY);
				
				app.window.setView(view);
			}
        }

        app.window.display();
    }

    void PlayPhase::OnLeave() {}
}