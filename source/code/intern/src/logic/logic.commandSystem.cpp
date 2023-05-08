#include "logic.commandSystem.h"

#include <assert.h>

namespace Logic 
{
    Command& CommandSystem::CreateCommand() 
    {
        return *(new Command());
    }

    void CommandSystem::AddCommand(Command& command) 
    {
        commandQueue.push(&command);
    }

    Command& CommandSystem::GetNextInQueue() 
    {
        assert(!commandQueue.empty());

        return *commandQueue.front();
    }

    void CommandSystem::RemoveNextInQueue() 
    {
        Command* command = commandQueue.front();
        delete command;
        commandQueue.pop();
    }

    bool CommandSystem::CommandQueueIsEmpty() const 
    {
        return commandQueue.empty();
    }
}