//
// Created by pierreantoine on 03/10/16.
//

#ifndef PEPPER_ORE_DIV_H
#define PEPPER_ORE_DIV_H

#include "composite.h"

namespace SC
{
    namespace pepper
    {
        namespace html
        {
            class div : public html::composite
            {
            public:
                div () :
                        composite ("hr")
                {}

                virtual ~hr ()
                {}

            private:
            protected:
            };
        }//ns html
    }//ns pepper
}//ns pa

#endif //PEPPER_ORE_DIV_H
