//
// Created by pierreantoine on 03/10/16.
//

#ifndef PEPPER_ORE_COMPOSITE_H
#define PEPPER_ORE_COMPOSITE_H


#include "component.h"

    namespace pepper
    {
        namespace html
        {
            class composite : public html::component
            {
            public:
                composite (const std::string & tag) noexcept;

                virtual std::string edit () const noexcept;

                virtual ~composite ()
                {}

            private:

                //std::ordered_set<pepper::html::component> children;

            protected:
                std::string edit_children() const;
            };
        }//ns html
    }//ns pepper


#endif //PEPPER_ORE_COMPOSITE_H
