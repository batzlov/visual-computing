
#pragma once

namespace Data
{
    class Event
    {
        public:
            using BTypeID = int;

        public:
            void SetType(BTypeID typeId);
            BTypeID GetType() const;

        protected:
            BTypeID typeId;

        protected:
            Event();
            virtual ~Event();
    };
}
