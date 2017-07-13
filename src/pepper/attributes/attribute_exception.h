
#ifndef PEPPER_ORE_ATTRIBUTE_EXCEPTION_H
#define PEPPER_ORE_ATTRIBUTE_EXCEPTION_H

#include <exception>

namespace pepper
{
    namespace attribute
    {
        class attribute_exception : public std::exception
        {
        public:
            attribute_exception ();

        private:
        protected:
        };
    }
}//ns pepper

#endif //PEPPER_ORE_ATTRIBUTE_EXCEPTION_H