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
    string temp = " ";
    for (const std::pair<string,string>& p : tags)
        temp+= p.first + "=\"" + p.second + "\"";
    return temp;
}
