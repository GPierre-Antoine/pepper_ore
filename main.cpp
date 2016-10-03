#include <iostream>     //cout
#include <vector>       //vector
#include <memory>       //shared ptr
#include "src/pepper/html/hr.hpp"
#include "src/pepper/html/img.hpp"
#include "src/pepper/attributes/attribute.h"

using namespace SC::pepper::html;
using std::cout;
using std::endl;
using namespace std;

using namespace SC::pepper::attribute;


int main ()
{
    vector<shared_ptr<component>> vec;
    vector<shared_ptr<attribute>> attributes;


    vec.push_back (shared_ptr<component>(new hr()));
    vec.push_back (shared_ptr<component>(new img()));

    attributes.push_back (shared_ptr<attribute>(new attribute ("src","/a/b/c")));
    attributes.push_back (shared_ptr<attribute>(new attribute ("width","320")));
    attributes.push_back (shared_ptr<attribute>(new attribute ("height","320")));
    attributes.push_back (shared_ptr<attribute>(new attribute ("test","320")));


    for (const shared_ptr<attribute> & i : attributes)
        vec[1]->attribute_insert (*i);

    for (const shared_ptr<component> & it : vec)
        cout << it->edit () << endl;
    return 0;
}