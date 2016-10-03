//
// Created by pierreantoine on 03/10/16.
//

#include "composite.h"

using namespace SC::pepper::html;


composite::composite(const std::string &tag) : component(tag)
{

}

std::string SC::pepper::html::composite::edit() const noexcept
{
    return '<' + node_id + edit_tags ()+'>'
            + edit_children ()
            + "</" + node_id+">";
}

std::string composite::edit_children() const {
    return std::string();
}
