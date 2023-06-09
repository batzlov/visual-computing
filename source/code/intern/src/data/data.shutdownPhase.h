#pragma once

namespace Data 
{
    class ShutdownPhase
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

        public: 
            void OnEnter();
            void OnRun();
            void OnLeave();
    };
}