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
            
            void SetLooksRight(bool looksRight);
            bool GetLooksRight();

            void Intoxicate();
            void SoberUp();
            bool IsIntoxicated();
            void UpdateIntoxication();

            void Die();
            bool DeadSequenceIsOver();
            bool IsDead();

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
            PlayerSystem()
                : looksRight(true)
                , isIntoxicated(false)
                , wasIntoxicatedAt(0.0)
                , intoxicatedFor(5.0)
                , isDead(false)
                , diedAt(0.0)
                , showDeadMessageFor(5.0)
            {
                InitPhysics();
            };

        private:
            bool looksRight;

            bool isIntoxicated;
            double wasIntoxicatedAt;
            double intoxicatedFor;

            bool isDead;
            double diedAt;
            double showDeadMessageFor;

            Entity* player;
    };
}