
#ifndef PEPPER_ORE_ATTRIBUTES_H
#define PEPPER_ORE_ATTRIBUTES_H


#include <string>
#include "attribute_exception.h"

namespace pa
{

    namespace html_attr
    {
        class attribute
        {
        public:
            attribute (const std::string & key) noexcept;
            attribute (const std::string & key, const std::string & value) noexcept;
            attribute (const attribute & other) noexcept;

            virtual std::string edit () const noexcept;

            void operator = (const attribute & other) throw (attribute_exception);

            bool operator == (const attribute & other) const noexcept;
            bool has_same_key_as (const attribute & other) const noexcept;

            const std::string & get_key () const noexcept;
            const std::string & get_value () const noexcept;
        private:
            const std::string key;
            std::string value;
        protected:
            void set_value (const std::string & value) noexcept;

        };
    }//ns html
}//ns pa

#endif //PEPPER_ORE_ATTRIBUTES_H