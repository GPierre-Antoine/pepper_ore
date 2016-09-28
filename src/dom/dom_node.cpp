//
// Created by Pierre-Antoine on 10/08/2016.
//

#include "dom_node.h"

using pa::html::dom_node;
using std::string;

dom_node::dom_node (const string & node_name) : node_id (node_name)
{

}

dom_node::dom_node (const dom_node & other) : node_id (other.node_id)
{

}

bool dom_node::operator == (const dom_node & other) const
{
    //todo 10/08/2016 better comparison
    if (&other == this)
        return true;
    return other.node_id == this->node_id;

}

std::string dom_node::edit_tags () const noexcept
{
    if (!tags.size()) return "";
    std::string temp;
    for (const pa::html_attr::attribute & p : tags)
        temp += ' ' + p.edit ();
    return temp;
}

dom_node & dom_node::attribute_insert (const pa::html_attr::attribute & attr)
{
    tags.insert(attr);
    return *this;
}

dom_node & dom_node::attribute_remove (const html_attr::attribute & attr)
{
    tags.erase(attr);
    return *this;
}
