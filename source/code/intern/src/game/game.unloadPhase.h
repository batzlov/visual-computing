#pragma once

#include "game.phase.h"

namespace Game 
{
    class UnloadPhase : public Phase
    {
        public: 
            static UnloadPhase& GetInstance()
            {
                static UnloadPhase instance;
                return instance;
            };
            
            UnloadPhase(const UnloadPhase&) = delete;
            UnloadPhase& operator = (const UnloadPhase&) = delete;

        private: 
            UnloadPhase() {};

        private: 
            int InternOnEnter();
            int InternOnRun();
            int InternOnLeave();
    };
}