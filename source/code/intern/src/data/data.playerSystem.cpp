#include <iostream>

#include "data.playerSystem.h"

namespace Data 
{
    Entity* PlayerSystem::GetPlayer()
    {
        return player;
    }

    void PlayerSystem::SetPlayer(Entity* player)
    {
        this->player = player;
    }

    void PlayerSystem::InitPhysics()
    {
        this->velocityX = 20.0f;
        this->velocityY = 20.0f;

        this->minVelocity = 1.0f;
        this->maxVelocity = 30.0f;
        this->acceleration = 3.0f;
        this->drag = 0.93f;
        this->gravity = 4.0f;
        this->maxVelocityY = 15.0f;
    }

    void PlayerSystem::UpdatePhysics() 
    {
        // gravity
        this->velocityY += 1.0f * this->gravity;
        if (std::abs(this->velocityX) > this->maxVelocityY)
        {
            this->velocityY = this->maxVelocityY * ((this->velocityY < 0.0f) ? -1.0f : 1.0f);
        }

        // deceleration
        this->velocityX *= this->drag;
        this->velocityY *= this->drag;

        // limit deceleration
        if (std::abs(this->velocityX) < this->minVelocity)
        {
            this->velocityX = 0.0f;
        }

        if (std::abs(this->velocityY) < this->minVelocity)
        {
            this->velocityY = 0.0f;
        }
    }

    void PlayerSystem::MovePlayer(const float directionX, const float directionY)
    {
        // acceleration
        this->velocityX += directionX * this->acceleration;

        // limit velocity
        if (std::abs(this->velocityX) > this->maxVelocity)
        {
            this->velocityX = this->maxVelocity * ((this->velocityX < 0.0f) ? -1.0f : 1.0f);
        }

        this->player->position = Core::Float2(
            this->player->position[0] + directionX,
            this->player->position[1] + directionY
            // this->player->position[1] - this->velocityY
        );
    }
}