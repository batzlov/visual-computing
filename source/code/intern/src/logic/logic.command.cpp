#include "logic.command.h"

namespace Logic 
{
    Command::Command() 
        : type(Logic::CommandType::Undefined) {}

    Command::~Command() {}

    Logic::CommandType Command::GetType() const 
    {
        return type;
    }

    void Command::SetType(Logic::CommandType type) 
    {
        this->type = type;
    }
}