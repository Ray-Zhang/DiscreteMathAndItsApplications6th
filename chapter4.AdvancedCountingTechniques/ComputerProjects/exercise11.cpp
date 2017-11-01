/*
 * exercise11.cpp
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given a positive integer n, list all the derangements of the
 * set {1,2,3,...,n}.
 */

#include <iostream>
#include <vector>

using IntVec = std::vector<int>;
bool NextDerangement(IntVec &result);
bool IsDerangement(const IntVec &result);

auto main() -> int
{
    IntVec iv{1,2,3,4,5};
    while (NextDerangement(iv))
    {
        for (auto item : iv)
            std::cout << item << " ";
        std::cout << std::endl;
    }
}

bool NextDerangement(IntVec &result)
{
    while (std::next_permutation(result.begin(), result.end()))
    {
        if (IsDerangement(result))
            return true;
    }
    return false;
}

bool IsDerangement(const IntVec &result)
{
    unsigned sz = result.size();
    for (int i = 0; i < sz; i++)
    {
        if (result[i] == i + 1)
            return false;
    }
    return true;
}
