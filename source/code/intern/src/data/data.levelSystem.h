#pragma once

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

        private:
            LevelSystem();

            LevelSystem(const LevelSystem&) = delete;
            LevelSystem& operator = (const LevelSystem&) = delete;

            int selectedLevel;
    };
}