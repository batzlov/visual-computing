#include <iostream>

#include "logic.system.h"
#include "logic.command.h"
#include "logic.commandSystem.h"

#include "../core/core.floatCompare.h"

#include "../data/data.playerSystem.h"
#include "../data/data.entitySystem.h"
#include "../data/data.eventSystem.h"
#include "../data/data.mapSystem.h"

namespace Logic 
{
    void System::OnTurn()
    {
        HandleCommands();
        HandleGravity();

        Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
        playerSystem.UpdateIntoxication();

        if (playerSystem.IsDead() && playerSystem.DeadSequenceIsOver())
        {
            Data::EventSystem::GetInstance().FireEvent(Data::EventType::PlayerDied);

            playerSystem.Revive();
        }
    }

    void System::HandleCommands()
    {
        float verticalStep = -75.0f;
        float horizontalStep = 15.0f;

        CommandSystem& commandSystem = CommandSystem::GetInstance();
        Command* command;

        while (!commandSystem.CommandQueueIsEmpty())
        {
            command = &commandSystem.GetNextInQueue();

            switch (command->GetType())
            {
                case Data::CommandAction::MoveLeft:
					MovePlayer(Core::Float2(-horizontalStep, 0));
					break;

                case Data::CommandAction::MoveLeftAndJump:
                    MovePlayer(Core::Float2(-horizontalStep, verticalStep));
					break;

                case Data::CommandAction::MoveRight:
                    MovePlayer(Core::Float2(horizontalStep, 0));
					break;

                case Data::CommandAction::MoveRightAndJump:
					MovePlayer(Core::Float2(horizontalStep, verticalStep));
                break;

				case Data::CommandAction::Jump:
					MovePlayer(Core::Float2(0, verticalStep));
                    break;

                default:
                    break;
            }

            commandSystem.RemoveNextInQueue();
        }
    }

    void System::HandleGravity()
    {
        Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
        Data::Entity* player = playerSystem.GetPlayer();

        // check for collisions
        bool* playerMovementIsBlocked = new bool(false);
        std::vector<Data::Entity*> collidingEntities = GetCollidingEntities(player->aabb);
        HandleCollisions(collidingEntities, *playerMovementIsBlocked);

        bool playerIsWalkingOnGround = PlayerIsWalkingOnGround();
        bool playerIsWalkingOnPlattform = PlayerIsWalkingOnPlattform();

        if (!playerIsWalkingOnGround && !playerIsWalkingOnPlattform)
        {
            playerSystem.MovePlayer(Core::Float2(0.0f, 25.0f));
        }
    }

    std::vector<Data::Entity*> System::GetCollidingEntities(Core::CAABB2<float> aabb)
    {
		Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
		Data::Entity* player = playerSystem.GetPlayer();

		std::vector<Data::Entity*> entities = Data::EntitySystem::GetInstance().GetAllCollidables();
		std::vector<Data::Entity*> collidingEntities;

        for (Data::Entity* entity : entities)
        {
            if (entity == nullptr)
            {
                continue;
            }

            if (aabb.Intersects(entity->aabb) == true)
            {
                collidingEntities.push_back(entity);
            }
        }

        return collidingEntities;
    }

    void System::HandleCollisions(std::vector<Data::Entity*> collisionEntities, bool& playerMovementIsBlocked)
    {
        Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();

        for (Data::Entity* entity : collisionEntities)
        {
            switch (entity->category)
            {
                case Data::EntityCategory::Finish:
                    Data::EventSystem::GetInstance().FireEvent(Data::EventType::FinishedMap);
                    break;

                case Data::EntityCategory::ShroomMagic:
                    Data::PlayerSystem::GetInstance().Intoxicate();
                    Data::EntitySystem::GetInstance().Destroy(*entity);
                    break;

                case Data::EntityCategory::ShroomToxic:
                    Data::PlayerSystem::GetInstance().Die();
                    Data::EntitySystem::GetInstance().Destroy(*entity);
                    break;

                case Data::EntityCategory::Obstacle:
                    playerMovementIsBlocked = true;
                    break;
            }
        }
	}

    void System::MovePlayer(Core::Float2 orientation)
    {
        Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
        Data::Entity* player = playerSystem.GetPlayer();
        
        if(player == nullptr || playerSystem.IsDead()) 
        {
            return;
        }

        // limit movement of the player so it doesn't go out of the screen
        float mapStartX = Data::MapSystem::GetInstance().GetMapStart();
        float mapEndX = Data::MapSystem::GetInstance().GetMapEnd();

        bool orientationXIsPositive = orientation[0] >= 0;
        // player moves left
        if (player->position[0] <= mapStartX && !orientationXIsPositive)
        {
			return;
		}

        // player moves right
        if (player->position[0] >= mapEndX && orientationXIsPositive)
        {
            return;
        }

        // set the orientation of the player and draw the sprite accordingly
        // change the orientation only if it has changed
        bool looksRight = Core::FloatCompare(0.0f, orientation[0]) == false ? orientationXIsPositive : playerSystem.GetLooksRight();
        playerSystem.SetLooksRight(looksRight);

        // handle the collision
        Core::CAABB2<float> movedPlayerAabb = Core::CAABB2<float>(
            Core::Float2(
                player->position[0] + orientation[0] + 1,
                player->position[1] + orientation[1] + 1
            ),
            Core::Float2(
                player->position[0] + orientation[0] + (player->size[0] - 1),
                player->position[1] + orientation[1] + (player->size[1] - 1)
            )
        );
        bool* playerMovementIsBlocked = new bool(false);
        std::vector<Data::Entity*> collidingEntities = GetCollidingEntities(movedPlayerAabb);
        HandleCollisions(collidingEntities, *playerMovementIsBlocked);

        if (!*playerMovementIsBlocked)
        {
            playerSystem.MovePlayer(orientation);
        }
    }

    bool System::PlayerIsWalkingOnPlattform()
    {
        Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
        Data::Entity* player = playerSystem.GetPlayer();

        Data::EntitySystem& entitySystem = Data::EntitySystem::GetInstance();
        auto entities = entitySystem.GetAllWalkables();
        
        float playerBottom = player->aabb.GetMax()[1];
        for (const auto& entity : entities) {
            float entityTop = entity->aabb.GetMin()[1];
                
            if (
                Core::FloatCompare(playerBottom, entityTop) &&
                player->aabb.GetCenter()[0] >= entity->aabb.GetMin()[0] &&
                player->aabb.GetCenter()[0] <= entity->aabb.GetMax()[0]
            ) 
            {
                return true;
            }
        }
        
        return false;
    }

    bool System::PlayerIsWalkingOnGround()
    {
        Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
        Data::Entity* player = playerSystem.GetPlayer();

        return !(player->position[1] < 450.0f);
    }
}