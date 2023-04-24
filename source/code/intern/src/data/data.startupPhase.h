#pragma once

namespace Data 
{
    class StartupPhase
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

        public: 
            void OnEnter();
            void OnRun();
            void OnLeave();
    };
}