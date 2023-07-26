#include <iostream>

#include "logic.system.h"
#include "logic.command.h"
#include "logic.commandSystem.h"

#include "../data/data.playerSystem.h"
#include "../data/data.entitySystem.h"

namespace Logic 
{
    void System::OnTurn()
    {
        HandleCommands();

        Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
        Data::Entity* player = playerSystem.GetPlayer();

        CheckPlayerIsWalkingOnGround();

        /*
            if (!PlayerIsWalkingOnGround())
            {
                player->position[1] = player->position[1] + 50.0f;
            }
        */
        
        // playerSystem.UpdatePhysics();
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
                    MovePlayer(Core::Float2(-15, -100));
					break;

                case Data::CommandAction::MoveRight:
                    MovePlayer(Core::Float2(15, 0));
					break;

                case Data::CommandAction::MoveRightAndJump:
					MovePlayer(Core::Float2(15, -100));
                break;

				case Data::CommandAction::Jump:
					MovePlayer(Core::Float2(0, -100));
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

        bool orientationXIsPositive = orientation[0] > 0;

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

        // playerSystem.UpdatePhysics();
        playerSystem.MovePlayer(orientation[0], orientation[1]);
    }

    bool System::CheckPlayerIsWalkingOnGround()
    {
        bool isWalkingOnGround = false;

		Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
		Data::Entity* player = playerSystem.GetPlayer();

        // compare two float values
        auto compareFloats = [](float a, float b) -> bool
        {
			float epsilon = 0.0001f;
			return std::abs(a - b) < epsilon;
		};

        if (compareFloats(player->position[1], 450.0f))
        {
			isWalkingOnGround = true;
            return isWalkingOnGround;
        }

        Data::EntitySystem& entitySystem = Data::EntitySystem::GetInstance();
        auto entities = entitySystem.GetAll();

        for (auto entity : entities)
        {
            // check if there is a platform under the player
        }

		return isWalkingOnGround;
	}
}