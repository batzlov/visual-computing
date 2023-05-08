#pragma once

namespace Logic 
{
    class PlayPhase 
    {
        public:
            static PlayPhase& GetInstance()
            {
                static PlayPhase instance;
                return instance;
            };
            
            PlayPhase(const PlayPhase&) = delete;
            PlayPhase& operator = (const PlayPhase&) = delete;

        public:
            void OnEnter();
            void OnRun();
            void OnLeave();

        private:
            PlayPhase() {};

        private:
            static const unsigned int turnsPerSecond = 10;
            const double turnInterval = 1.0 / turnsPerSecond;
            double nextTurnTime;
    };
}