#include "data.levelSystem.h"

namespace Data
{
    LevelSystem::LevelSystem()
        : selectedLevel(1) {}

    int LevelSystem::GetSelectedLevel() const
    {
        return selectedLevel;
    }

    void LevelSystem::SetSelectedLevel(int level)
    {
        selectedLevel = level;
    }
}