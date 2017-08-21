/*
 * exercise01.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given two finite sets, list all elements in the Cartesian
 * product of these two sets.
 */
#include "SetHelper.h"
#include <set>
#include <cassert>
#include <iostream>

int main(void)
{
    std::set<int> int_set({1,2});
    std::set<double> double_set({1.1,2.2});
    CartesianProducts<int, double> output({});
    GenerateCartesianProduct(output, int_set, double_set);
    assert(output.size() == 4);
    for (auto elem : output)
    {
        std::cout << elem.first << ":" << elem.second << std::endl;
    }

    return 0;
}


