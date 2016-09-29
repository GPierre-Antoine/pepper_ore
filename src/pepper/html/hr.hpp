
#ifndef PEPPER_ORE_HR_H
#define PEPPER_ORE_HR_H

#include "leaf_node.h"

namespace SC
{
    namespace pepper
    {
        namespace html
        {
            class hr : public html::leaf_node
            {
            public:
                hr () :
                        leaf_node ("hr")
                {}

                virtual ~hr ()
                {}

            private:
            protected:
            };
        }//ns html
    }//ns pepper
}//ns pa

#endif //PEPPER_ORE_HR_H