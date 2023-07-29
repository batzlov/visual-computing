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
            ShroomMagic,
            ShroomToxic,
            NumberOfMembers,
            Undefined = -1,
        };
    };
}
