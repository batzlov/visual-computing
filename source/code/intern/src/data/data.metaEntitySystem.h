#pragma once

#include <tinyxml2.h>

#include "../core/core.idManager.h"
#include "../core/core.itemManager.h"

#include "data.metaEntity.h"

namespace Data 
{
    class MetaEntitySystem
    {
        public:
            static MetaEntitySystem& GetInstance()
            {
                static MetaEntitySystem instance;
                return instance;
            }

            MetaEntitySystem(const MetaEntitySystem&) = delete;
            MetaEntitySystem& operator = (const MetaEntitySystem&) = delete;
            
        public:
            int Initialize(tinyxml2::XMLDocument& document);

        private:
            MetaEntitySystem() {}

        private:
            Core::CIDManager idManager;
            Core::CItemManager<MetaEntity> itemManager;
    };
}