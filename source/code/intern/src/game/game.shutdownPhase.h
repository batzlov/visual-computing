#pragma once

#include "game.phase.h"

namespace Game 
{
    class ShutdownPhase : public Phase
    {
        public: 
            static ShutdownPhase& GetInstance()
            {
                static ShutdownPhase instance;
                return instance;
            };
            
            ShutdownPhase(const ShutdownPhase&) = delete;
            ShutdownPhase& operator = (const ShutdownPhase&) = delete;

        private: 
            ShutdownPhase() {};

        private: 
            int InternOnEnter();
            int InternOnRun();
            int InternOnLeave();
    };
}