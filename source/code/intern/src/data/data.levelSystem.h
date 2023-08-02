#pragma once

#include <string>

namespace Data 
{
    class LevelSystem
    {
        public:
            static LevelSystem& GetInstance()
            {
                static LevelSystem instance;
                return instance;
            };

            int GetSelectedLevel() const;
            void SetSelectedLevel(int level);

            std::string GetSelectedLevelAsString();
            std::string GetSelectedLevelFileName();

        private:
            LevelSystem();

            LevelSystem(const LevelSystem&) = delete;
            LevelSystem& operator = (const LevelSystem&) = delete;

            int selectedLevel;
    };
}