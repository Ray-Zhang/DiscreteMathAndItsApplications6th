/*
 * exercise02.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given positive integers n and r, find the number
 * of r-permutations when repetition is allowed and r-
 * combinations when repetition is allowed of a set with n
 * elements.
 */

#include <cassert>
#include <stdlib.h>
#include <iostream>
#include <cmath>

int PermutationCountRepetitionAllowed(int n, int r);
int CombinationCountRepetitionAllowed(int n, int r);
int CombinationCount(int n, int r);

int main(void)
{
    // tests for PermutationCountRepetitionAllowed
    assert(PermutationCountRepetitionAllowed(2, 10) == 1024);
    assert(PermutationCountRepetitionAllowed(0, 10) == 0);
    assert(PermutationCountRepetitionAllowed(10, 0) == 1);
    assert(PermutationCountRepetitionAllowed(0, 0) == 1);

    // tests for CombinationCountRepetitionAllowed
    assert(CombinationCountRepetitionAllowed(8, 10) == 19448);
    assert(CombinationCountRepetitionAllowed(0, 10) == 0);
    assert(CombinationCountRepetitionAllowed(10, 0) == 1);
    assert(CombinationCountRepetitionAllowed(0, 0) == 1);

    return 0;
}

int CombinationCount(int n, int r)
{
    int ret_val = 1;
    if (r > n)
    {
        std::cout << "Error: r is greater than n" << std::endl;
        exit(1);
    }
    if (r > n / 2)
        r = n - r;
    for (int i = n; i > n - r; i--)
    {
        ret_val *= i;
    }
    for (int i = r; i > 1; i--)
    {
        ret_val /= i;
    }

    return ret_val;
}

int PermutationCountRepetitionAllowed(int n, int r)
{
    return static_cast<int>(pow(n, r));
}

int CombinationCountRepetitionAllowed(int n, int r)
{
    if (n == 0 && r != 0)
        return 0;
    else if (n == 0)
        return 1;
    else
        return CombinationCount(n + r - 1, r);
}
