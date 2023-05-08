#include "data.playerSystem.h"

namespace Data 
{
    Entity* PlayerSystem::GetPlayer()
    {
        return player;
    }

    void PlayerSystem::SetPlayer(Entity* player)
    {
        this->player = player;
    }
}