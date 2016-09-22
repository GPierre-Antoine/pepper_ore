
#ifndef PEPPER_ORE_LEAF_NODE_H
#define PEPPER_ORE_LEAF_NODE_H

#include "dom_node.h"

namespace pa
{

    namespace html
    {
        class leaf_node : public html::dom_node
        {
        public:
            leaf_node (const std::string & tag) noexcept;
            virtual std::string edit() const noexcept;
            virtual ~leaf_node () {}
        private:

        protected:
        };
    }//ns html
}//ns pa

#endif //PEPPER_ORE_LEAF_NODE_H