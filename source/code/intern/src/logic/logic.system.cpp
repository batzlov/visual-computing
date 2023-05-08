#include <iostream>

#include "logic.system.h"
#include "logic.command.h"
#include "logic.commandSystem.h"

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
                    MovePlayer("left");
                    break;
                case CommandType::MoveRight:
                    MovePlayer("right");
                    break;
                case CommandType::Jump:
                    MovePlayer("jump");
                    break;
                default:
                    break;
            }

            commandSystem.RemoveNextInQueue();
        }
    }

    void System::MovePlayer(std::string direction)
    {
        std::cout << "Player moved " << direction << std::endl;
    }
}