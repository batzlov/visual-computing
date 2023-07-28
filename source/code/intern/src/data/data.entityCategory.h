#pragma once

namespace Data
{
    struct EntityCategory
    {
        enum Enum
        {
            Character,
            Ground,
            Plattform,
            Obstacle,
            Finish,
            NumberOfMembers,
            Undefined = -1,
        };
    };
}
