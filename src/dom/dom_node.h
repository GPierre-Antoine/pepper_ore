
#ifndef PEPPER_ORE_DOM_NODE_H
#define PEPPER_ORE_DOM_NODE_H

#include <string>
#include <vector>

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
            virtual std::string edit () const noexcept = 0;
            virtual ~dom_node () {}
        private:
        protected:
            std::string edit_tags () const noexcept;
            std::string node_id;
            std::vector<std::pair<std::string,std::string>> tags;

        };
    }//ns html
}//ns pa

#endif //PEPPER_ORE_DOM_NODE_H