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
                    MovePlayer(Core::Float2(-1, 0));
                    break;
                case CommandType::MoveRight:
                    MovePlayer(Core::Float2(1, 0));
                    break;
                case CommandType::Jump:
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
            playerSystem.UpdatePhysics();
            playerSystem.MovePlayer(orientation[0], orientation[1]);
        }
    }
}