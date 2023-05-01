#include "data.metaEntity.h"

namespace Data 
{
    MetaEntity::MetaEntity() {}

    MetaEntity::MetaEntity(int id, std::string name)
        : id(id)
        , name(name)
    {}

    MetaEntity::~MetaEntity() {}

    // int MetaEntity::GetId()
    // {
    //     return id;
    // }

    // void MetaEntity::SetId(int id)
    // {
    //     this->id = id;
    // }

    // std::string MetaEntity::GetName()
    // {
    //     return name;
    // }

    // void MetaEntity::SetName(std::string name)
    // {
    //     this->name = name;
    // }
}