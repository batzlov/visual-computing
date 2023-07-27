#pragma once

#include <string>

#include "../core/core.vector.h"

namespace Logic
{
    class System 
    {
        public:
            static System& GetInstance()
            {
                static System instance;
                return instance;
            }

            System(const System&) = delete;
            System& operator = (const System&) = delete;

        public:
            void OnTurn();

        public: 
            void HandleCommands();
            void MovePlayer(Core::Float2 orientation);

            bool PlayerIsWalkingOnPlattform();
            bool PlayerIsWalkingOnGround();

        private:
            System() {};
    };
}