#pragma once

#include "game.phase.h"
#include <data/data.event.h>

namespace Game
{
    class MainMenuPhase : public Phase
    {
        public:
            static MainMenuPhase& GetInstance()
            {
                static MainMenuPhase instance;
                return instance;
            };

            MainMenuPhase(MainMenuPhase const&) = delete;
            MainMenuPhase& operator=(MainMenuPhase const&) = delete;

        // event callbacks
        public:
            static void OnStart(Data::Event& event);
            static void OnEnter(Data::Event& event);
            static void OnUp(Data::Event& event);
            static void OnDown(Data::Event& event);
            static void OnExit(Data::Event& event);

        private:
            MainMenuPhase() {};

            Phase::Type nextRunPhase;

        private:
            int InternOnEnter() override;
            int InternOnRun() override;
            int InternOnLeave() override;
    };
}