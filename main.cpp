#include <iostream>     //cout
#include <vector>       //vector
#include <memory>       //shared ptr
#include "src/dom/hr.hpp"
#include "src/dom/img.hpp"
#include "src/dom/attributes/attribute.h"

using namespace pa::html;
using std::cout;
using std::endl;
using namespace std;

using namespace pa::html_attr;


int main ()
{
    vector<shared_ptr<dom_node>> vec;
    vector<shared_ptr<attribute>> attributes;


    vec.push_back (shared_ptr<dom_node>(new hr()));
    vec.push_back (shared_ptr<dom_node>(new img()));

    attributes.push_back (shared_ptr<attribute>(new attribute ("src","/a/b/c")));
    attributes.push_back (shared_ptr<attribute>(new attribute ("width","320")));
    attributes.push_back (shared_ptr<attribute>(new attribute ("height","320")));

    for (const shared_ptr<attribute> & i : attributes)
        vec[1]->attribute_insert (*i);

    for (const shared_ptr<dom_node> & it : vec)
        cout << it->edit () << endl;
    return 0;
}