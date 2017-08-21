/*
 * exercise02.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Give a finite set, list all elements of its power set.
 */

#include "SetHelper.h"
#include <cassert>
#include <iostream>

int main(void)
{
    Powerset<int> output({});
    std::set<int> normal_case({1,2,3});
    GeneratePowerSets(output, normal_case);
    int i = 1;
    for (auto elem_set : output)
    {
        std::cout << "set " << i++ << std::endl;
        for (auto elem : elem_set)
        {
            std::cout << elem << std::endl;
        }
    }
    assert(output.size() == 8);

    return 0;
}


