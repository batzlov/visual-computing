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

        Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
        Data::Entity* player = playerSystem.GetPlayer();

        if(player != nullptr && player->position[1] < 450.0f) 
        {
            player->position[1] = player->position[1] + 10.f;
            std::cout << "player position y: " << player->position[1] << std::endl;
        
            std::cout << "Player is in the air.." << std::endl;
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
                case CommandType::MoveLeft:
                    MovePlayer(Core::Float2(-10, 0));
                    break;
                case CommandType::MoveRight:
                    std::cout << "Move right" << std::endl;
                    MovePlayer(Core::Float2(10, 0));
                    break;
                case CommandType::Jump:
                    std::cout << "Jump" << std::endl;
                    MovePlayer(Core::Float2(0, -50));
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
        
        if(player != nullptr) 
        {
            // playerSystem.UpdatePhysics();
            // playerSystem.MovePlayer(orientation[0], orientation[1]);

            player->position[0] += orientation[0];
            player->position[1] += orientation[1];
        }
    }
}