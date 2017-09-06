//
// Created by pa on 14/07/17.
//

#ifndef PEPPER_JS_DEPENDECY_H
#define PEPPER_JS_DEPENDECY_H

#include <vector>
#include "abstract_dependency.h"
#include "js_manager.h"

namespace pepper
{
    namespace dependency
    {
        class js_dependency : abstract_dependency
        {
            std::string lib;
            std::vector<js_dependency> requirements;
        public:
            js_dependency(const std::string &lib, const std::initializer_list<js_dependency> &requirements);

            bool operator == (const js_dependency& rhm) const noexcept;
            virtual void ask_dependency(js_manager & manager) const noexcept;
            virtual std::string get () const override;
        };

        js_dependency jquery ("vendor/jquery",{});
        js_dependency jquery_ui ("vendor/jquery-ui",jquery);
        js_dependency bootstrap ("vendor/bootstrap",jquery);
    }
}

namespace std
{
    template <>
    class hash<pepper::dependency::js_dependency>
    {
    public:
        size_t operator()(const pepper::dependency::js_dependency & target) const
        {
            std::hash<std::string> hash_fn;return hash_fn(target.get());
        }
    };
}

#endif //PEPPER_JS_DEPENDECY_H
