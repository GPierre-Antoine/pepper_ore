
#ifndef PEPPER_ORE_DOM_NODE_H
#define PEPPER_ORE_DOM_NODE_H

#include <string>
#include <unordered_set>
#include <functional>

#include "../attributes/attribute.h"

namespace SC
{
    namespace pepper
    {
        namespace html
        {
            class node
            {
            public:
                node (const std::string & node_name);

                node (const node & other);

                bool operator == (const node & other) const;

                node & attribute_insert (const pepper::attribute::attribute & attr);

                node & attribute_remove (const pepper::attribute::attribute & attr);

                //todo iterator.

                virtual std::string edit () const noexcept = 0;

                virtual ~node ()
                {}

            private:
            protected:
                std::string edit_tags () const noexcept;

                std::string node_id;
                std::unordered_set<SC::pepper::attribute::attribute> tags;

            };
        }//ns html
    }//ns peppper
}//ns pa

#endif //PEPPER_ORE_DOM_NODE_H