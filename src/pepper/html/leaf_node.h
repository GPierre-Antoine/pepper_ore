
#ifndef PEPPER_ORE_LEAF_NODE_H
#define PEPPER_ORE_LEAF_NODE_H

#include "node.h"

namespace SC
{
    namespace pepper
    {
        namespace html
        {
            class leaf_node : public html::node
            {
            public:
                leaf_node (const std::string & tag) noexcept;

                virtual std::string edit () const noexcept;

                virtual ~leaf_node ()
                {}

            private:

            protected:
            };
        }//ns html
    }//ns pepper
}//ns pa

#endif //PEPPER_ORE_LEAF_NODE_H