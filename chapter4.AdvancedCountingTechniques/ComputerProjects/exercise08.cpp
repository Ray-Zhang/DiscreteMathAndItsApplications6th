/*
 * exercise08.cpp
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given the number of elements in the intersection of three
 * sets, the number of elements in each pairwise intersection
 * of these sets, and the number of elements in each set, find
 * the nubmer of elements in their union
 */

#include <iostream>

unsigned CountOfUnion(unsigned intersectionCountThree, unsigned intersectionCountPair_1,
        unsigned intersectionCountPair_2, unsigned intersectionCountPair_3,
        unsigned setCount_1, unsigned setCount_2, unsigned setCount_3);

auto main() -> int
{
    std::cout << CountOfUnion(2, 3, 4, 5, 6, 7, 8) << std::endl;

    return 0;
}

unsigned CountOfUnion(unsigned intersectionCountThree, unsigned intersectionCountPair_1,
        unsigned intersectionCountPair_2, unsigned intersectionCountPair_3,
        unsigned setCount_1, unsigned setCount_2, unsigned setCount_3)
{
    return setCount_1 + setCount_2 + setCount_3 - intersectionCountPair_1
        - intersectionCountPair_2 - intersectionCountPair_3 + intersectionCountThree;
}

