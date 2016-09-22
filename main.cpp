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
    attribute attr = attribute("img","src/aze/aze");
    vector<shared_ptr<dom_node>> vec;
    vec.push_back (shared_ptr<dom_node>(new hr()));
    vec.push_back (shared_ptr<dom_node>(new img()));
    for (const shared_ptr<dom_node> & it : vec)
        cout << it->edit () << endl;
    return 0;
}