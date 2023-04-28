#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "gui/gui.mainMenuPhase.h"

namespace Gfx 
{
    class MainMenuPhase 
    {
        public: static MainMenuPhase& GetInstance()
        {
            static MainMenuPhase instance;
            return instance;
        };
        
        MainMenuPhase(const MainMenuPhase&) = delete;
        MainMenuPhase& operator = (const MainMenuPhase&) = delete;

        public: 
            void Initialize();
            void Render();

            void OnEnter();
            void OnRun();
            void OnLeave();

        private: 
            MainMenuPhase() {};

            sf::Texture textures[Gui::SelectedMenuLabel::Length];
            sf::Sprite screens[Gui::SelectedMenuLabel::Length];
    };
}