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

            NumberOfEventTypes,
            Undefined = -1
        };
    };
}