//
// Created by Pierre-Antoine on 11/08/2016.
//

#include "attribute.h"

using pa::html_attr::attribute;

attribute::attribute (const std::string & key, const std::string & value) noexcept : key (key), value (value)
{

}

attribute::attribute (const std::string & key) noexcept : key (key)
{

}

attribute::attribute (const attribute & other) noexcept : key (other.key), value (other.value)
{

}

void attribute::operator = (const attribute & other) throw (attribute_exception)
{
    if (!has_same_key_as (other))
        throw attribute_exception ();
    set_value (other.get_value ());
}

bool attribute::operator == (const attribute & other) const noexcept
{
    return ((this == &other) | ((get_key () == other.get_key ()) & (get_value () == other.get_value ())));
}

std::string attribute::edit () const noexcept
{
    char separator = '"';
    if (value.find ('"') != std::string::npos)
        separator = '\'';
    return get_key () + '=' + separator + get_value () + separator;
}

const std::string & attribute::get_key () const noexcept
{
    return key;
}

const std::string & attribute::get_value () const noexcept
{
    return value;
}

void attribute::set_value (const std::string & value) noexcept
{
    attribute::value = value;
}

bool attribute::has_same_key_as (const attribute & other) const noexcept
{
    return ((this == &other) | (get_key () == other.get_key ()));
}