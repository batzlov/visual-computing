#include <iostream>

#include "logic.system.h"
#include "logic.command.h"
#include "logic.commandSystem.h"

#include "../core/core.floatCompare.h"

#include "../data/data.playerSystem.h"
#include "../data/data.entitySystem.h"
#include "../data/data.eventSystem.h"

namespace Logic 
{
    void System::OnTurn()
    {
        HandleCommands();

        Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
        Data::Entity* player = playerSystem.GetPlayer();

        bool playerIsWalkingOnGround = PlayerIsWalkingOnGround();
        bool playerIsWalkingOnPlattform = PlayerIsWalkingOnPlattform();

        if (!playerIsWalkingOnGround && !playerIsWalkingOnPlattform)
        {
            player->position[1] = player->position[1] + 25.0f;

            player->aabb = Core::CAABB2<float>(
                Core::Float2(player->position[0], player->position[1]),
                Core::Float2(player->position[0] + 50, player->position[1] + 50)
            );
		}
    }

    void System::HandleCommands()
    {
        CommandSystem& commandSystem = CommandSystem::GetInstance();
        Command* command;

        while (!commandSystem.CommandQueueIsEmpty())
        {
            command = &commandSystem.GetNextInQueue();

            switch (command->GetType())
            {
                case Data::CommandAction::MoveLeft:
					MovePlayer(Core::Float2(-15, 0));
					break;

                case Data::CommandAction::MoveLeftAndJump:
                    MovePlayer(Core::Float2(-15, -75));
					break;

                case Data::CommandAction::MoveRight:
                    MovePlayer(Core::Float2(15, 0));
					break;

                case Data::CommandAction::MoveRightAndJump:
					MovePlayer(Core::Float2(15, -75));
                break;

				case Data::CommandAction::Jump:
					MovePlayer(Core::Float2(0, -75));
                    break;

                default:
                    break;
            }

            commandSystem.RemoveNextInQueue();
        }
    }

    void System::MovePlayer(Core::Float2 orientation)
    {
        Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
        Data::Entity* player = playerSystem.GetPlayer();
        
        if(player == nullptr) 
        {
            return;
        }

        // limit movement of the player so it doesn't go out of the screen
        float mapStartX = 25;
        float mapEndX = 1525;

        bool orientationXIsPositive = orientation[0] >= 0;

        // set the orientation of the player and draw the sprite accordingly
        // change the orientation only if it has changed
        bool looksRight = Core::FloatCompare(0.0f, orientation[0]) == false ? orientationXIsPositive : playerSystem.GetLooksRight();
        playerSystem.SetLooksRight(looksRight);

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

        // handle the collision
        std::vector<Data::Entity*> entities = Data::EntitySystem::GetInstance().GetAllCollidables();
        std::vector<Data::Entity*> collidingEntities;

        for (Data::Entity* entity : entities)
        {
            if (entity == nullptr)
            {
				continue;
			}

            Core::CAABB2<float> movedPlayerAabb = Core::CAABB2<float>(
				Core::Float2(player->position[0] + orientation[0] + 1, player->position[1] + orientation[1] + 1),
				Core::Float2(player->position[0] + orientation[0] + 49, player->position[1] + orientation[1] + 49)
			);

            if (movedPlayerAabb.Intersects(entity->aabb) == true)
            {
                if (entity->category == Data::EntityCategory::Enum::Finish)
                {
                    Data::EventSystem::GetInstance().FireEvent(Data::EventType::FinishedMap);
				}
                else if (entity->category == Data::EntityCategory::Obstacle)
                {
                    return;
                }

                collidingEntities.push_back(entity);
            }
		}   

        // FIXME: ???
        playerSystem.MovePlayer(orientation[0], orientation[1]);
        player->aabb = Core::CAABB2<float>(
            Core::Float2(player->position[0] + orientation[0], player->position[1] + orientation[1]),
            Core::Float2(player->position[0] + orientation[0] + 50, player->position[1] + orientation[1] + 50)
        );
    }

    bool System::PlayerIsWalkingOnPlattform()
    {
        // function to compare floats
        auto floatCompare = [](float a, float b) -> bool {
			return fabs(a - b) < 0.005f;
		};

        Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
        Data::Entity* player = playerSystem.GetPlayer();

        Data::EntitySystem& entitySystem = Data::EntitySystem::GetInstance();
        auto entities = entitySystem.GetAllCollidables();
        
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