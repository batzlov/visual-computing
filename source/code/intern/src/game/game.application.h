#pragma once
#include <iostream>

#include "game.phase.h"
#include <SFML/Graphics/RenderWindow.hpp>

enum HandlePhaseChangeResult
{
    PHASE_REMAINS,
    PHASE_CHANGED,
    GAME_LIFECYCLE_ENDED
};

namespace Game
{
    class Application
    {
        public:
            static Application& GetInstance()
            {
                static Application instance;
                return instance;
            };

            Application(const Application&) = delete;
            Application& operator = (const Application&) = delete;

        private:
            Application();
            int currentPhaseIndex;
            Phase* phases [Phase::NumberOfTypes];

        public:
            sf::RenderWindow window;

        public:
            void Startup();
            void Run();
            void Shutdown();

        private:
            void HandleEvent(sf::Event event);
            HandlePhaseChangeResult HandlePhaseChange();
    };
}