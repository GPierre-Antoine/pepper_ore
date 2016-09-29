//
// Created by Pierre-Antoine on 10/08/2016.
//

#include "node.h"

using SC::pepper::html::node;
using std::string;

node::node (const string & node_name) : node_id (node_name)
{

}

node::node (const node & other) : node_id (other.node_id)
{

}

bool node::operator == (const node & other) const
{
    //todo 10/08/2016 better comparison
    if (&other == this)
        return true;
    return other.node_id == this->node_id;

}

std::string node::edit_tags () const noexcept
{
    if (!tags.size()) return "";
    std::string temp;
    for (const SC::pepper::attribute::attribute & p : tags)
        temp += ' ' + p.edit ();
    return temp;
}

node & node::attribute_insert (const SC::pepper::attribute::attribute & attr)
{
    tags.insert(attr);
    return *this;
}

node & node::attribute_remove (const SC::pepper::attribute::attribute & attr)
{
    tags.erase(attr);
    return *this;
}
