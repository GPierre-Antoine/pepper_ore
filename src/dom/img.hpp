
#ifndef PEPPER_ORE_IMG_H
#define PEPPER_ORE_IMG_H

#include "leaf_node.h"

namespace pa
{
    namespace html
    {
        class img : public leaf_node
        {
        public:
            img () : leaf_node ("img") {}
            virtual ~img () {}
        private:
        protected:
        };
    }//ns html
}//ns pa

#endif //PEPPER_ORE_IMG_H