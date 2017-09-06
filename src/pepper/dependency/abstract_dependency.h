//
// Created by pa on 14/07/17.
//

#ifndef PEPPER_ABSTRACT_DEPENDENCY_H
#define PEPPER_ABSTRACT_DEPENDENCY_H

#include <string>
#include <memory>


namespace pepper
{
    namespace dependency
    {
        class abstract_dependency
        {
        public:
            virtual std::string get () const = 0;
            virtual ~ abstract_dependency(){}
        private:
        protected:
        };
    }
}

namespace std
{
    template <>
    class hash<pepper::dependency::abstract_dependency>
    {
    public:
        size_t operator()(const pepper::dependency::abstract_dependency & target) const
        {
            std::hash<std::string> hash_fn;return hash_fn(target.get());
        }
    };
}

#endif //PEPPER_ABSTRACT_DEPENDENCY_H
