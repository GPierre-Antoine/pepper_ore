
#ifndef PEPPER_ORE_DOM_NODE_H
#define PEPPER_ORE_DOM_NODE_H

#include <string>
#include <unordered_set>
#include <functional>

#include "../attributes/attribute.h"


namespace pepper
{
    namespace html
    {
        class component
        {
        public:
            component (const std::string & node_name);

            component (const component & other);

            bool operator == (const component & other) const;

            component & add (const pepper::attribute::attribute &attr);

            component & remove (const pepper::attribute::attribute &attr);

            //todo iterator.

            virtual std::string edit () const noexcept = 0;

            virtual ~component ()
            {}

        private:
        protected:
            std::string edit_tags () const noexcept;

            std::string node_id;
            std::unordered_set<pepper::attribute::attribute> tags;

        };
    }//ns html
}//ns peppper

#endif //PEPPER_ORE_DOM_NODE_H