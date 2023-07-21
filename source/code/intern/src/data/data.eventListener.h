
#pragma once

namespace Data
{
    class Event;
}

namespace Data
{
    // function pointer to a static method of a class or a global C method
    using EventListener = void (*) (Event& event);
}
