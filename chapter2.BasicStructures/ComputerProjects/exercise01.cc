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

#include <iostream>
#include <set>
#include <string>
#include <cassert>
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

/*
std::string Union(const std::string &original_set_a, const std::string &original_set_b)
{
}
*/

int main(void)
{
    // SetToBinaryString tests
    // set of ints
    {
        std::set<int> universal_int({1,2,3,4,5,6,7,8,9,0});
        std::set<int> normal_test_case({1,2,5,7,0});
        assert(SetToBinaryString(universal_int, normal_test_case) == std::string("1110010100"));
        std::set<int> empty_test_case({});
        assert(SetToBinaryString(universal_int, empty_test_case) == std::string("0000000000"));
        std::set<int> full_test_case({1,2,3,4,5,6,7,8,9,0});
        assert(SetToBinaryString(universal_int, full_test_case) == std::string("1111111111"));
    }
    // set of strings
    {
        std::set<std::string> universal_string({"str1", "str2", "str3"});
        std::set<std::string> normal({"str1", "str3"});
        assert(SetToBinaryString(universal_string, normal) == std::string("101"));
        std::set<std::string> empty_string({});
        assert(SetToBinaryString(universal_string, empty_string) == std::string("000"));
        std::set<std::string> full_string({"str1", "str2", "str3"});
        assert(SetToBinaryString(universal_string, full_string) == std::string("111"));
    }

    // Complement tests
    {
        assert(Complement(std::string("1100110")) == std::string("0011001"));
        assert(Complement(std::string("1111111")) == std::string("0000000"));
        assert(Complement(std::string("0000000")) == std::string("1111111"));
    }

    return 0;
}
