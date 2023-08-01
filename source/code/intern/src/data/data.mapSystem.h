#pragma once

#include <tinyxml2.h>

namespace Data 
{
    class MapSystem
    {
        public:
            static MapSystem& GetInstance()
            {
                static MapSystem instance;
                return instance;
            }

            MapSystem(const MapSystem&) = delete;
            MapSystem& operator = (const MapSystem&) = delete;

            float GetHeight();
            float GetWidth();

            float GetMapStart();
            float GetMapEnd();

            float GetViewBorderStart();
            float GetViewBorderEnd();

            void Initialize(tinyxml2::XMLDocument& document);

        private:
            MapSystem();

            float height;
            float width;
    };
}