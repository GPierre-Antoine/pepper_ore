//
// Created by Pierre-Antoine on 11/08/2016.
//

#include "attribute.h"

#define MAGICAL_VAR_TYPE string

using pepper::attribute::attribute;

attribute::attribute (const std::MAGICAL_VAR_TYPE & key,
                      const std::MAGICAL_VAR_TYPE & value) noexcept : key (key), value (value)
{

}

attribute::attribute (const std::MAGICAL_VAR_TYPE & key) noexcept : key (key)
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
    return has_same_key_as (other) && other.get_value () == get_value ();
}

std::MAGICAL_VAR_TYPE attribute::edit () const noexcept
{
    char separator = '"';
    if (value.find ('"') != std::string::npos)
        separator = '\'';
    return get_key () + '=' + separator + get_value () + separator;
}

const std::MAGICAL_VAR_TYPE & attribute::get_key () const noexcept
{
    return key;
}

const std::MAGICAL_VAR_TYPE & attribute::get_value () const noexcept
{
    return value;
}

void attribute::set_value (const std::MAGICAL_VAR_TYPE & value) noexcept
{
    attribute::value = value;
}

bool attribute::has_same_key_as (const attribute & other) const noexcept
{
    return ((this == &other) | (get_key () == other.get_key ()));
}

#undef MAGICAL_VAR_TYPE
