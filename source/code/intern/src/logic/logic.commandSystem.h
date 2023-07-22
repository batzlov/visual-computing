#pragma once

#include <queue>

#include "logic.command.h"
#include "../data/data.event.h"

namespace Logic 
{
    class CommandSystem 
    {
        using CommandQueue = std::queue<Command*>;

        public:
            static CommandSystem& GetInstance()
            {
                static CommandSystem instance;
                return instance;
            }

            CommandSystem(const CommandSystem&) = delete;
            CommandSystem& operator = (const CommandSystem&) = delete;

        public:
            Command& CreateCommand();
            void AddCommand(Command& command);
            Command& GetNextInQueue();
            void RemoveNextInQueue();
            bool CommandQueueIsEmpty() const;

            // event callbacks
            static void DispatchInputToLogic(Data::Event& event);

        private:
            CommandSystem() {}

        private:
            CommandQueue commandQueue;
    };
}