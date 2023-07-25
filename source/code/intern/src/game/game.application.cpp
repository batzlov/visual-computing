#include <SFML/Graphics.hpp>
#include <iostream>
#include <cassert>
#include <unordered_map>

#include "game.application.h"
#include "game.phase.h"
#include "game.startupPhase.h"
#include "game.mainMenuPhase.h"
#include "game.loadPhase.h"
#include "game.playPhase.h"
#include "game.unloadPhase.h"
#include "game.shutdownPhase.h"

#include "data/data.eventSystem.h"
#include "logic/logic.commandSystem.h"

namespace Game 
{
    Application::Application()
        : currentPhaseIndex(Phase::Undefined)
    {
        phases[Phase::STARTUP] = &StartupPhase::GetInstance(); 
        phases[Phase::MAIN_MENU] = &MainMenuPhase::GetInstance();
        phases[Phase::LOAD_MAP] = &LoadPhase::GetInstance();
        phases[Phase::PLAY] = &PlayPhase::GetInstance();
        phases[Phase::UNLOAD_MAP] = &UnloadPhase::GetInstance();
        phases[Phase::SHUTDOWN] = &ShutdownPhase::GetInstance();
    }

    void Application::Startup()
    {
        // create the window
        window.create(sf::VideoMode(800, 600), "Visual Computing - Robert Ackermann");
        window.setFramerateLimit(60);

        currentPhaseIndex = Phase::STARTUP;
        Phase* currentPhase = phases[currentPhaseIndex];
        assert(currentPhase != nullptr);
        currentPhase->OnEnter();
    }

    void Application::Run()
    {
        std::unordered_map<int, bool> pressedKeys;
        
        // game loop
        for (;;) 
        {
            if (window.isOpen() == false) 
            {
                break;
            }

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }

                // if the key is pressed, and it is not already in the map, add it
                if (event.type == sf::Event::KeyPressed && pressedKeys.count(event.key.code) == 0)
				{
					pressedKeys[event.key.code] = true;
				}

                // if the key is released, and it is in the map, remove it
                if (event.type == sf::Event::KeyReleased && pressedKeys.count(event.key.code) == 1)
                {
                    pressedKeys.erase(event.key.code);
                }

                // FIXME: this is not working as expected and should be removed in the future
                // HandleEvent(event);
            }

            for (auto& key : pressedKeys)
            {
                Data::EventSystem::GetInstance().FireEvent(Data::EventType::DispatchEventToInput, key.first);
            }

            // exit if the lifecycle ended
            if (HandlePhaseChange() == GAME_LIFECYCLE_ENDED)
            {
                break;
            }
        }
    }

    void Application::Shutdown() {}

    void Application::HandleEvent(sf::Event event)
    {
        std::cout << "Handle event is called.." << std::endl;

        if(event.type == sf::Event::Closed)
		{
			window.close();
		}

        if (event.type == sf::Event::KeyPressed)
        {
            Data::EventSystem::GetInstance().FireEvent(Data::EventType::DispatchEventToInput, event.key.code);
        }

        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                Data::EventSystem::GetInstance().FireEvent(Data::EventType::DispatchEventToInput, sf::Keyboard::Left);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
                Data::EventSystem::GetInstance().FireEvent(Data::EventType::DispatchEventToInput, sf::Keyboard::Right);
			}
        }

        /*
            switch (event.type)
            {
                case sf::Event::Resized:
                    // update the view to the new size of the window
                    // sf::FloatRect visibleArea(0, 0, (float) event.size.width, (float) event.size.height);
                break;

                case sf::Event::KeyPressed:
                    Data::EventSystem::GetInstance().FireEvent(Data::EventType::DispatchEventToInput, event.key.code);
                break;


                case sf::Event::Closed: 
                    window.close();
                break;

                default:
                    std::cout << "default event case" << event.type << std::endl;
                break;
            }
        */
    }

    HandlePhaseChangeResult Application::HandlePhaseChange()
    {
        Phase* currentPhase = phases[currentPhaseIndex];
        assert(currentPhase != nullptr);
        
        int nextPhaseIndex = currentPhase->OnRun();
        if (nextPhaseIndex != currentPhaseIndex) 
        {
            // handle the transistion from one phase to another
            currentPhase->OnLeave();

            // we can exit at this point if the shutdown phase is entered
            if (currentPhaseIndex == Phase::SHUTDOWN) 
            {
                return GAME_LIFECYCLE_ENDED;
            }

            // update current phase index and the actual phase
            currentPhaseIndex = nextPhaseIndex;
            currentPhase = phases[currentPhaseIndex];

            // check if phase is valid and enter the new phase
            assert(currentPhase != nullptr);
            currentPhase->OnEnter();

            return PHASE_CHANGED;
        }

        return PHASE_REMAINS;
    }
}

int main()
{
    Game::Application& app = Game::Application::GetInstance();

    app.Startup();
    app.Run();
    app.Shutdown();
    
    return 0;
}