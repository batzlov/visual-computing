#include <iostream>

#include "logic.system.h"
#include "logic.command.h"
#include "logic.commandSystem.h"

#include "../data/data.playerSystem.h"

namespace Logic 
{
    void System::OnTurn()
    {
        HandleCommands();
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
                case CommandType::MoveLeft:
                    MovePlayer(Core::Float2(-10, 0));
                    break;
                case CommandType::MoveRight:
                    MovePlayer(Core::Float2(10, 0));
                    break;
                case CommandType::Jump:
                    MovePlayer(Core::Float2(0, 100));
                    break;
                default:
                    std::cout << "default" << std::endl;
                    break;
            }

            commandSystem.RemoveNextInQueue();
        }
    }

    void System::MovePlayer(Core::Float2 orientation)
    {
        Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
        Data::Entity* player = playerSystem.GetPlayer();
        
        if(player != nullptr) 
        {
            std::cout << "player before updating position -> " << player->position[0] << " - " << player->position[1] << std::endl;
           
            // update player position
            player->position = Core::Float2(
                player->position[0] + orientation[0],
                player->position[1] + orientation[1]
            );

            std::cout << "player after updating position -> " << player->position[0] << " - " << player->position[1] << std::endl;
        }
        else
        {
            std::cout << "player is nullptr" << std::endl;
        }
    }
}