#pragma once

namespace Data 
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

        private: 
            LoadPhase() {};

        public: 
            void OnEnter();
            void OnRun();
            void OnLeave();
    };
}