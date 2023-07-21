#include "logic.command.h"

#include "../data/data.commandAction.h"

namespace Logic 
{
    Command::Command() 
        : type(Data::CommandAction::Enum::Undefined) {}

    Command::~Command() {}

    Data::CommandAction::Enum Command::GetType() const 
    {
        return type;
    }

    void Command::SetType(Data::CommandAction::Enum type)
    {
        this->type = type;
    }
}