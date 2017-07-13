
#ifndef PEPPER_ORE_HR_H
#define PEPPER_ORE_HR_H

#include "leaf.h"


    namespace pepper
    {
        namespace html
        {
            class hr : public html::leaf
            {
            public:
                hr () :
                        leaf ("hr")
                {}

                virtual ~hr ()
                {}

            private:
            protected:
            };
        }//ns html
    }//ns pepper

#endif //PEPPER_ORE_HR_H