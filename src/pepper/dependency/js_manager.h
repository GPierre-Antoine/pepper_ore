//
// Created by pa on 14/07/17.
//

#ifndef PEPPER_JS_MANAGER_H
#define PEPPER_JS_MANAGER_H

#include <unordered_set>

#include "js_dependency.h"
#include "abstract_manager.h"

namespace pepper
{
    namespace dependency
    {
        class js_manager : abstract_manager<pepper::dependency::js_dependency>
        {
        public:
            virtual void require(const pepper::dependency::js_dependency & dep);
        private:
            std::unordered_set<pepper::dependency::js_dependency> scripts;
        protected:
        };
    }
}


#endif //PEPPER_JS_MANAGER_H
