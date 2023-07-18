#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "gfx.playPhase.h"
#include "core/core.config.h"
#include "game/game.application.h";
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

        std::string filePath = Core::Config::backgroundDirs + "beach.jpg";
        sf::Texture bgTexture;
        bgTexture.loadFromFile(filePath.c_str());

        sf::Sprite bgSprite;
        bgSprite.setScale(0.5, 0.5);
        bgSprite.setTexture(bgTexture);

        // get instance of player system
        Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
        Data::Entity* player = playerSystem.GetPlayer();

        // set the background position to follow the player
        bgSprite.setPosition(player->position[0] - 150, 0);

        app.window.draw(bgSprite);
        
        // get all entities we need to draw
        std::vector<Data::Entity*> entities = Data::EntitySystem::GetInstance().GetAll();
        for(auto entity : entities) 
        {
            std::string filePath;
            sf::Texture* entityTexture;
            sf::Sprite entitySprite;

            entityTexture = static_cast<sf::Texture*>(entity->metaEntity->facets[0]);

            entitySprite.setTexture(*entityTexture);
            entitySprite.setScale(0.25, 0.25);
            entitySprite.setPosition(entity->position[0], entity->position[1]);

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

				sf::View view = app.window.getView();

                float centerX = entity->position[0] + 250;
                float centerY = entity->position[1] - 150;

                view.setCenter(centerX, centerY);
				
				app.window.setView(view);
			}
        }

        app.window.display();
    }

    void PlayPhase::OnLeave() {}
}