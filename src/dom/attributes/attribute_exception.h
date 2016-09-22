
#ifndef PEPPER_ORE_ATTRIBUTE_EXCEPTION_H
#define PEPPER_ORE_ATTRIBUTE_EXCEPTION_H

#include <exception>
namespace pa
{

    namespace html_attr
    {
        class attribute_exception : public std::exception
        {
        public:
            attribute_exception ();
        private:
        protected:
        };
    }//ns html
}//ns pa

#endif //PEPPER_ORE_ATTRIBUTE_EXCEPTION_H