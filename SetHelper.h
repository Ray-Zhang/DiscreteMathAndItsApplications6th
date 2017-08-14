/*
 * exercise01.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given subsets A and B of a set with n elements,
 * use bit strings to find A's complement, union
 * of A and B, and intersection of A and B
 */

#include <set>
#include <string>

template <class T>
std::string SetToBinaryString(const std::set<T> &universal_set, const std::set<T> &original_set)
{
    std::string ret_value("");
    for (auto elem: universal_set)
    {
        if (original_set.find(elem) == original_set.end())
            ret_value += "0";
        else
            ret_value += "1";
    }

    return ret_value;
}
