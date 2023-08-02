#pragma once

#include <string>
#include <vector>

#include "../data/data.entity.h"
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
            void HandleGravity();

            std::vector<Data::Entity*> GetCollidingEntities(Core::CAABB2<float> aabb);
            void HandleCollisions(std::vector<Data::Entity*> collisionEntities, bool& playerMovementIsBlocked);

            void MovePlayer(Core::Float2 orientation);

            bool PlayerIsWalkingOnPlattform();
            bool PlayerIsWalkingOnGround();

        private:
            System() {};
    };
}