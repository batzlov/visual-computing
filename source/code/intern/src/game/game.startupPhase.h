#pragma once

#include "game.phase.h"

namespace Game 
{
    class StartupPhase : public Phase
    {
        public: 
            static StartupPhase& GetInstance()
            {
                static StartupPhase instance;
                return instance;
            };
            
            StartupPhase(const StartupPhase&) = delete;
            StartupPhase& operator = (const StartupPhase&) = delete;

        private: 
            StartupPhase() {};

        private: 
            int InternOnEnter();
            int InternOnRun();
            int InternOnLeave();
    };
}