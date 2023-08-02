
#include <iostream>

#include "data.playerSystem.h"

#include "../core/core.time.h"

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

    void PlayerSystem::SetLooksRight(bool looksRight)
    {
		this->looksRight = looksRight;
	}

    bool PlayerSystem::GetLooksRight()
    {
        return this->looksRight;
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

    void PlayerSystem::MovePlayer(Core::Float2 distance)
    {
        /*
            // acceleration
            this->velocityX += directionX * this->acceleration;

            // limit velocity
            if (std::abs(this->velocityX) > this->maxVelocity)
            {
                this->velocityX = this->maxVelocity * ((this->velocityX < 0.0f) ? -1.0f : 1.0f);
            }
        */
        

        this->player->position = Core::Float2(
            this->player->position[0] + distance[0],
            this->player->position[1] + distance[1]
        );
        this->player->aabb = Core::CAABB2<float>(
            Core::Float2(
                this->player->position[0],
                this->player->position[1]
            ),
            Core::Float2(
                this->player->position[0] + this->player->size[0],
                this->player->position[1] + this->player->size[1]
            )
        );
    }

    void PlayerSystem::Intoxicate()
    {
		this->isIntoxicated = true;
		this->wasIntoxicatedAt = Core::Time::GetTime();
	}

    bool PlayerSystem::IsIntoxicated()
    {
		return this->isIntoxicated;
	}

    void PlayerSystem::SoberUp()
    {
        this->isIntoxicated = false;
        this->wasIntoxicatedAt = 0.0;
    }

    void PlayerSystem::UpdateIntoxication()
    {
        if (!this->isIntoxicated)
        {
            return;
		}

        if (Core::Time::GetTime() - this->wasIntoxicatedAt > this->intoxicatedFor)
        {
			this->SoberUp();
		}
	}

    void PlayerSystem::Die()
    {
		this->isDead = true;
		this->diedAt = Core::Time::GetTime();
	}

    void PlayerSystem::Revive()
    {
        this->isDead = false;
        this->diedAt = 0.0;
    }

    bool PlayerSystem::DeadSequenceIsOver()
    {
		return Core::Time::GetTime() - this->diedAt > this->showDeadMessageFor;
	}

    bool PlayerSystem::IsDead()
    {
		return this->isDead;
	}
}