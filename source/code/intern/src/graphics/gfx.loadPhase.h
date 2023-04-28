#pragma once

#include <SFML/Graphics.hpp>

namespace Gfx
{
    class LoadPhase 
    {
        public:
            static LoadPhase& GetInstance()
            {
                static LoadPhase instance;
                return instance;
            };
            
            LoadPhase(const LoadPhase&) = delete;
            LoadPhase& operator = (const LoadPhase&) = delete;

        public:
            void Initialize();
            void Render();

            void OnEnter();
            void OnRun();
            void OnLeave();

        private:
            LoadPhase() {};

            sf::Texture texture;
            sf::Sprite screen;
    };
}