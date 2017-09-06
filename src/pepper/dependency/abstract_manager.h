//
// Created by pa on 14/07/17.
//

#ifndef PEPPER_MANAGER_H
#define PEPPER_MANAGER_H

#include <type_traits>

#include "abstract_dependency.h"


namespace pepper
{
    namespace dependency
    {
        template <typename derived_dependency,
                typename = typename std::enable_if<std::is_base_of<pepper::dependency::abstract_dependency,derived_dependency>::value>>
        class abstract_manager
        {
        public:
            virtual void require(const derived_dependency & dep)= 0;
            virtual ~ abstract_manager(){}
        private:
        protected:
        };
    }
}

#endif //PEPPER_MANAGER_H
