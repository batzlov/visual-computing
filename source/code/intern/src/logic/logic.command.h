#pragma once

#include "../data/data.commandAction.h"

namespace Logic 
{
    class Command 
    {
        public:
            Command();
            ~Command();

        public:
            Data::CommandAction::Enum GetType() const;
            void SetType(Data::CommandAction::Enum type);

        private:
            Data::CommandAction::Enum type;
    };
}