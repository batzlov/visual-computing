#include <SFML/Graphics.hpp>
#include <iostream>

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
        std::cout << "Application::Startup()" << std::endl;

        // create the window
        window.create(sf::VideoMode(800, 600), "Visual Computing - Robert Ackermann");
    }

    void Application::Run()
    {
        std::cout << "Application::Run()" << std::endl;

        // now we draw a simple green circle
        sf::CircleShape shape(200.f);
        shape.setFillColor(sf::Color::Green);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
                                        
            window.clear();                            
            window.draw(shape);
            window.display();
        }
    }

    void Application::Shutdown()
    {
        std::cout << "Application::Shutdown()" << std::endl;
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