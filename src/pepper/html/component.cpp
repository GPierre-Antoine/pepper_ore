//
// Created by Pierre-Antoine on 10/08/2016.
//

#include "component.h"

using SC::pepper::html::component;
using std::string;

component::component (const string & node_name) : node_id (node_name)
{

}

component::component (const component & other) : node_id (other.node_id)
{

}

bool component::operator == (const component & other) const
{
    //todo 10/08/2016 better comparison
    if (&other == this)
        return true;
    return other.node_id == this->node_id;

}

std::string component::edit_tags () const noexcept
{
    if (!tags.size()) return "";
    std::string temp;
    for (const SC::pepper::attribute::attribute & p : tags)
        temp += ' ' + p.edit ();
    return temp;
}

component & component::attribute_insert (const SC::pepper::attribute::attribute & attr)
{
    tags.insert(attr);
    return *this;
}

component & component::attribute_remove (const SC::pepper::attribute::attribute & attr)
{
    tags.erase(attr);
    return *this;
}
