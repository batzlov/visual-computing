#pragma once

namespace Logic 
{
    enum CommandType 
    {
        MoveLeft,
        MoveRight,
        Jump,
        NumberOfTypes,
        Undefined = -1
    };

    class Command 
    {
        public:
            Command();
            ~Command();

        public:
            CommandType GetType() const;
            void SetType(CommandType type);

        private:
            CommandType type;
    };
}