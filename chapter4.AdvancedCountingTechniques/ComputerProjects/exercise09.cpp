/*
 * exercise09.cpp
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 * 
 * Given a positive integer n, produc e the formula for the
 * number of elements in the union of n sets
 * e.g.: when n is 3, then N(S1|S2|S3) = N(S1) + N(S2) + N(S3) - N(S1&S2) - N(S1&S3) - N(S2&S3) + N(S1&S2&S3)
 */

#include <iostream>
#include <string>
#include <set>
#include <cmath>
#include <vector>

// Type T must have method size()
template <typename T>
class SetCompare
{
public:
    bool operator() (const T &lil, const T &ril) const
    {
        return lil.size() <= ril.size();
    }
};
using CombinationSetType = std::set<std::vector<int>, SetCompare<std::vector<int>>>;

auto GetOperator = [](unsigned n) { return (n % 2 == 0 ? "-" : "+"); };

// generate strings for like N(S1&S3) from list of integers
std::string GenerateSetCountString(std::vector<int> args, std::string operator_string);

// generate formula for n sets
std::string UnionCountFormula(unsigned n);

// get integer list by binary operation and
std::vector<int> GetIntegerList(unsigned);

auto main() -> int
{
    std::cout << UnionCountFormula(3u) << std::endl;
    std::cout << UnionCountFormula(4u) << std::endl;
    std::cout << UnionCountFormula(5u) << std::endl;

    return 0;
}



std::string GenerateSetCountString(std::vector<int> args, std::string operator_string)
{
    std::string result("N(");
    auto iter = std::begin(args);
    result += "S" + std::to_string(*iter++);
    for (;iter != std::end(args);iter++)
    {
        result += operator_string + "S" + std::to_string(*iter);
    }
    result += ")";
    return result;
};

std::string UnionCountFormula(unsigned n)
{
    std::string result("");
    result += GenerateSetCountString(GetIntegerList(std::pow(2, n)-1), "|") + " = ";

    CombinationSetType combSet{};
    int combCount = std::pow(2, n);
    for (unsigned i = 1; i < combCount; i++)
    {
        combSet.insert(GetIntegerList(i));
    }

    for (auto item : combSet)
    {
        result += GetOperator(item.size()) + GenerateSetCountString(item, "&");
    }

    return result;
}

std::vector<int> GetIntegerList(unsigned n)
{
    std::vector<int> result = {};
    const unsigned COMP = 0x01;
    int i = 1;
    while (n > 0)
    {
        if (n & COMP)
        {
            result.push_back(i);
        }
        n >>= 1;
        i++;
    }

    return result;
}


