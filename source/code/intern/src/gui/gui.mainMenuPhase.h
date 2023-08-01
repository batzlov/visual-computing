#pragma once

#include <SFML/System/Clock.hpp>

namespace Gui
{
    enum SelectedMenuLabel
    {
        PLAY,
        EXIT,
        Length
    };

    class MainMenuPhase
    {
        public:
            static MainMenuPhase& GetInstance()
            {
                static MainMenuPhase instance;
                return instance;
            };

            MainMenuPhase(const MainMenuPhase&) = delete;
            MainMenuPhase& operator = (const MainMenuPhase&) = delete;

        public:
            void OnEnter();
            int OnRun();
            void OnLeave();

            SelectedMenuLabel GetSelectedMenuLabel();
            void SetSelectedMenuLabel(SelectedMenuLabel selectedMenuLabel);

            int GetSelectedLevel() const;
            void SetSelectedLevel(int level);

            bool IndicateLevelChange();
            void SetIndicateLevelChange(bool indicateLevelChange);

        private:
            MainMenuPhase();

            SelectedMenuLabel selectedMenuLabel;
            bool enterPressed;
            bool escapePressed;

            int selectedLevel;
            bool indicateLevelChange;
            sf::Clock indicateLevelChangeTimer;
            double indicateLevelChangeDuration;
    };
}