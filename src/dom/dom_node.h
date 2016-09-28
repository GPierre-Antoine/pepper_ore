
#ifndef PEPPER_ORE_DOM_NODE_H
#define PEPPER_ORE_DOM_NODE_H

#include <string>
#include <unordered_set>
#include <functional>

#include "attributes/attribute.h"

namespace pa
{

    namespace html
    {
        class dom_node
        {
        public:
            dom_node (const std::string & node_name);
            dom_node (const dom_node & other);
            bool operator == (const dom_node & other) const;

            dom_node & attribute_insert (const html_attr::attribute & attr);
            dom_node & attribute_remove (const html_attr::attribute & attr);

            //todo iterator.

            virtual std::string edit () const noexcept = 0;
            virtual ~dom_node () {}
        private:
        protected:
            std::string edit_tags () const noexcept;
            std::string node_id;
            std::unordered_set<pa::html_attr::attribute> tags;

        };
    }//ns html
}//ns pa

#endif //PEPPER_ORE_DOM_NODE_H