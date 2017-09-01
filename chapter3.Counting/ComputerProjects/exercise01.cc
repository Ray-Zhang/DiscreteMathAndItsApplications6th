/*
 * exercise01.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given a positive integer n and a nonnegative integer not
 * exceeding n, find the number of r-permutations and r-
 * combinations of a set with n elements
 */

#include <cassert>
#include <stdlib.h>
#include <iostream>

int PermutationCount(int n, int r);
int CombinationCount(int n, int r);

int main(void)
{
    // test for PermutationCount
    assert(PermutationCount(3, 2) == 6);
    assert(PermutationCount(3, 0) == 1);
    assert(PermutationCount(0, 0) == 1);
    //assert(PermutationCount(2, 3) == 1);

    // test for CombinationCount
    assert(CombinationCount(3, 2) == 3);
    assert(CombinationCount(3, 0) == 1);
    assert(CombinationCount(0, 0) == 1);
    //assert(PermutationCount(2, 3) == 1);

    return 0;
}

int PermutationCount(int n, int r)
{
    int ret_val = 1;
    if (r > n)
    {
        std::cout << "Error: r is greater than n" << std::endl;
        exit(1);
    }
    for (int i = n; i > n - r; i--)
        ret_val *= i;

    return ret_val;
}

int CombinationCount(int n, int r)
{
    int ret_val = 1;
    if (r > n)
    {
        std::cout << "Error: r is greater than n" << std::endl;
        exit(1);
    }
    for (int i = n; i > n - r; i--)
        ret_val *= i;
    for (int i = r; i > 1; i--)
        ret_val /= i;

    return ret_val;
}

