#include <SFML/Graphics.hpp>
#include <iostream>
#include <cassert>

#include "game.application.h"
#include "game.phase.h"
#include "game.startupPhase.h"
#include "game.mainMenuPhase.h"
#include "game.loadPhase.h"
#include "game.playPhase.h"
#include "game.unloadPhase.h"
#include "game.shutdownPhase.h"

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
        window.create(sf::VideoMode(1600, 1200), "Visual Computing - Robert Ackermann");

        currentPhaseIndex = Phase::STARTUP;
        Phase* currentPhase = phases[currentPhaseIndex];
        assert(currentPhase != nullptr);
        currentPhase->OnEnter();
    }

    void Application::Run()
    {
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
                HandleEvent(event);
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
        switch (event.type)
        {
            case sf::Event::Resized:
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, (float) event.size.width, (float) event.size.height);
            }
            break;
            case sf::Event::KeyPressed:
            {
                // std::cout << "key pressed, key code: " << event.key.code << std::endl;
            }
            break;
            case sf::Event::Closed: 
            {
                window.close();
            }
            break;
            default:
            {
                // TODO: check if we need to handle other events
            }
            break;
        }
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