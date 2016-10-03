//
// Created by Pierre-Antoine on 11/08/2016.
//

#include "leaf.h"
#include <algorithm>

using SC::pepper::html::leaf;
using std::string;

leaf::leaf (const string & tag) noexcept : pepper::html::component (tag)
{
}

std::string leaf::edit () const noexcept
{

    return '<' + node_id + edit_tags ()+"/>";
}