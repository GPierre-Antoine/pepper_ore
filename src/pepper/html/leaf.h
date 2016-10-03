
#ifndef PEPPER_ORE_LEAF_NODE_H
#define PEPPER_ORE_LEAF_NODE_H

#include "component.h"

namespace SC
{
    namespace pepper
    {
        namespace html
        {
            class leaf : public html::component
            {
            public:
                leaf (const std::string & tag) noexcept;

                virtual std::string edit () const noexcept;

                virtual ~leaf ()
                {}

            private:

            protected:
            };
        }//ns html
    }//ns pepper
}//ns pa

#endif //PEPPER_ORE_LEAF_NODE_H