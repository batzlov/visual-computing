#include "data.metaEntity.h"

namespace Data 
{
    MetaEntity::MetaEntity() {}

    MetaEntity::MetaEntity(int _id, std::string _name, float _size, Core::AABB2Float _aabb)
        : id(_id)
        , name(_name)
        , size(_size)
        , aabb(_aabb)
    {}

    MetaEntity::~MetaEntity() {}
}