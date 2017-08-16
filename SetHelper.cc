/*
 * SetHelper.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given subsets A and B of a set with n elements,
 * use bit strings to find A's complement, union
 * of A and B, and intersection of A and B
 */

#include "SetHelper.h"

std::string Complement(const std::string &original_set)
{
    std::string ret_value("");
    for (auto elem : original_set)
    {
        if (elem == '0')
            ret_value += "1";
        else
            ret_value += "0";
    }

    return ret_value;
}

std::string Union(const std::string &original_set_a, const std::string &original_set_b)
{
    if (original_set_a.size() != original_set_b.size())
        return std::string("");
    std::string ret_value("");
    std::size_t string_length = original_set_a.size();
    for (int i = 0; i < string_length; i++)
    {
        if (original_set_a[i] == '1' || original_set_b[i] == '1')
            ret_value += "1";
        else
            ret_value += "0";
    }

    return ret_value;
}

std::string Intersection(const std::string &original_set_a, const std::string &original_set_b)
{
    if (original_set_a.size() != original_set_b.size())
        return std::string("");
    std::string ret_value("");
    std::size_t string_length = original_set_a.size();
    for (int i = 0; i < string_length; i++)
    {
        if (original_set_a[i] == '1' && original_set_b[i] == '1')
            ret_value += "1";
        else
            ret_value += "0";
    }

    return ret_value;
}

