#pragma once

#include <tinyxml2.h>

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
            void OnRun(tinyxml2::XMLDocument& document);
            void OnLeave();
    };
}