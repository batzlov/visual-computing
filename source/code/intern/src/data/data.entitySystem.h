#pragma once

#include <tinyxml2.h>

#include "../core/core.idManager.h"
#include "../core/core.itemManager.h"
#include "data.entity.h"

using namespace tinyxml2;

namespace Data 
{
    class EntitySystem 
    {
        public: 
            static EntitySystem& GetInstance()
            {
                static EntitySystem instance;
                return instance;
            }

            EntitySystem (const EntitySystem&) = delete;
            EntitySystem& operator = (const EntitySystem&) = delete;

        public:
            int Initialize(XMLDocument& document);
            std::vector<std::string> Explode(std::string string, const char& delimiter);
            std::vector<Data::Entity*> GetAll();

        private:
            EntitySystem() {};

        private:
            Core::CIDManager idManager;
            Core::CItemManager<Entity> itemManager;
    };
}