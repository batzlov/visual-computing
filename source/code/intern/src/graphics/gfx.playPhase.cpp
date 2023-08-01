#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "gfx.playPhase.h"
#include "core/core.config.h"
#include "game/game.application.h"
#include "data/data.entity.h"
#include "data/data.entitySystem.h"
#include "data/data.playerSystem.h"
#include "data/data.mapSystem.h"

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
        
        sf::IntRect bounds(
            0, 
            0, 
            Data::MapSystem::GetInstance().GetWidth(),
            Data::MapSystem::GetInstance().GetWidth()
        );
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
            if (entity == nullptr) {
                continue;
            }

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
                float minBorderX = Data::MapSystem::GetInstance().GetViewBorderStart();
                float maxBorderX = Data::MapSystem::GetInstance().GetViewBorderEnd();

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

        // check if the player is on a psychedlic journey, if so show it
        if (playerSystem.IsIntoxicated())
        {
            filePath = Core::Config::backgroundDirs + "psychedelic-2-compressed.jpg";
            sf::Texture psychedelicTexture;
            psychedelicTexture.loadFromFile(filePath.c_str());
            psychedelicTexture.setRepeated(true);

            sf::IntRect overlayBounds(0, 0, 1600, 1600);
            sf::Sprite psychedelicSprite = sf::Sprite(psychedelicTexture, overlayBounds);
            psychedelicSprite.setPosition(
                (float)bounds.left,
                (float)bounds.top - 700.0f + app.GetInstance().window.getView().getSize().y
            );
            psychedelicSprite.setColor(sf::Color(255, 255, 255, 128));

            app.window.draw(psychedelicSprite);
        }

        // check if the player died, if so show it
        if (playerSystem.IsDead())
        {
            // draw game over text
            sf::Font font;
            font.loadFromFile(Core::Config::fontsDir + "IndieFlower-Regular.ttf");
                                   
            sf::Text text;
            text.setString("Game Over");
            text.setFont(font);
            text.setCharacterSize(100);
            text.setFillColor(sf::Color::Red);

            // set position to center of the screen
            sf::Vector2f viewCenter = app.GetInstance().window.getView().getCenter();
            viewCenter.x = viewCenter.x - text.getLocalBounds().width / 2;
            viewCenter.y = viewCenter.y - text.getLocalBounds().height;
            text.setPosition(viewCenter);

            app.window.draw(text);
        }

        app.window.display();
    }

    void PlayPhase::OnLeave() {}
}