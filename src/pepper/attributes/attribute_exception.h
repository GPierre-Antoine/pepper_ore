
#ifndef PEPPER_ORE_ATTRIBUTE_EXCEPTION_H
#define PEPPER_ORE_ATTRIBUTE_EXCEPTION_H

#include <exception>
namespace SC
{
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
}//ns SC

#endif //PEPPER_ORE_ATTRIBUTE_EXCEPTION_H