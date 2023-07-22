#pragma once

namespace Data
{
    struct EventType
    {
        enum Enum
        {
            FinishedMap,

            DispatchEventToInput,
            DispatchInputToCommand,

            PressedEscape,
            PressedEnter,
            PressedUp,
            PressedDown,

            NumberOfEventTypes,
            Undefined = -1
        };
    };
}