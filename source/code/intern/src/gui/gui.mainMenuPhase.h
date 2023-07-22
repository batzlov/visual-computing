#pragma once

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

        private:
            MainMenuPhase();

            SelectedMenuLabel selectedMenuLabel;
            bool enterPressed;
            bool escapePressed;
    };
}