#include "data.unloadPhase.h"
#include "data.entitySystem.h"

namespace Data
{
    void UnloadPhase::OnEnter() {}

    void UnloadPhase::OnRun()
    {
        EntitySystem::GetInstance().DestroyAll();
    }

    void UnloadPhase::OnLeave() {}
}