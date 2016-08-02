
#ifndef PEPPER_ORE_DOM_NODE_H
#define PEPPER_ORE_DOM_NODE_H

//
//TODO 01/08/2016 replace namespace
namespace pa
{

    namespace dom
    {
        class dom_node
        {
        public:
            dom_node ();
            bool operator == (const dom_node & other) const;

        private:

        protected:
        };
    }//ns rdi
}//ns pa

#endif //PEPPER_ORE_DOM_NODE_H