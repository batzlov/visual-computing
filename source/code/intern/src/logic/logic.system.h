#pragma once

#include <string>

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
            void MovePlayer(std::string direction);


        private:
            System() {};
    };
}