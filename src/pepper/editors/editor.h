
#ifndef PEPPER_ORE_EDITOR_H
#define PEPPER_ORE_EDITOR_H

//
//TODO 28/09/2016 replace namespace

namespace pepper
{
    namespace editor
    {
        class editor
        {
        public:
            editor ();

            editor (const editor & other);

            void operator = (const editor & other);

            bool operator == (const editor & other) const;

        private:

        protected:
        };
    }//ns editor
}//ns pepper


#endif //PEPPER_ORE_EDITOR_H