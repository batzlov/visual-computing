#pragma once

#include "../core/core.vector.h"

#include "data.entity.h"

namespace Data 
{
    class PlayerSystem 
    {
        public:
            static PlayerSystem& GetInstance()
            {
                static PlayerSystem instance;
                return instance;
            };

            PlayerSystem(const PlayerSystem&) = delete;
            PlayerSystem& operator = (const PlayerSystem&) = delete;

        public:
            Entity* GetPlayer();
            void SetPlayer(Entity* player);

        public:
            void InitPhysics();
            void UpdatePhysics();
            void MovePlayer(const float directionX, const float directionY);
            float velocityX;
            float velocityY;
            float maxVelocity;
            float minVelocity;
            float acceleration;
            float drag;
            float gravity;
            float maxVelocityY;


        private:
            PlayerSystem() {
                InitPhysics();
            };

        private:
            Entity* player;
    };
}