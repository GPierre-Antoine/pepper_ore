
#ifndef PEPPER_ORE_ATTRIBUTES_H
#define PEPPER_ORE_ATTRIBUTES_H

#define MAGICAL_VAR_TYPE string

#include <string>
#include "attribute_exception.h"

namespace pepper
{
    namespace attribute
    {
        class attribute
        {
        public:
            attribute (const std::MAGICAL_VAR_TYPE & key) noexcept;

            attribute (const std::MAGICAL_VAR_TYPE & key,
                       const std::MAGICAL_VAR_TYPE & value) noexcept;

            attribute (const attribute & other) noexcept;

            virtual std::MAGICAL_VAR_TYPE edit () const noexcept;

            void operator = (const attribute & other) throw (attribute_exception);

            bool operator == (const attribute & other) const noexcept;

            bool has_same_key_as (const attribute & other) const noexcept;

            const std::MAGICAL_VAR_TYPE & get_key () const noexcept;

            const std::MAGICAL_VAR_TYPE & get_value () const noexcept;

        private:
            const std::MAGICAL_VAR_TYPE key;
            std::MAGICAL_VAR_TYPE value;
        protected:
            void set_value (const std::MAGICAL_VAR_TYPE & value) noexcept;

        };
    }//ns attribute
}//ns pepper

namespace std
{
    template <>
    struct hash<pepper::attribute::attribute>
    {
        size_t operator() (const pepper::attribute::attribute & key) const noexcept
        {
            return hash<std::MAGICAL_VAR_TYPE>()(key.get_key ());
        }
    };
}

#undef MAGICAL_VAR_TYPE
#endif //PEPPER_ORE_ATTRIBUTES_H