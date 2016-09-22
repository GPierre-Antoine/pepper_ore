//
// Created by Pierre-Antoine on 11/08/2016.
//

#include "leaf_node.h"
#include <algorithm>

using pa::html::leaf_node;
using std::string;

leaf_node::leaf_node (const string & tag) noexcept : dom_node (tag)
{
}

std::string leaf_node::edit () const noexcept
{

    return '<' + node_id + edit_tags ()+" />";
}