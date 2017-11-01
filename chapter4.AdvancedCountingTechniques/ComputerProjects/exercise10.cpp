/*
 * exercise10.cpp
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given positive integers m and n, find the number of onto
 * functions from a set with m elements to a set with n
 * elements
 */

#include <iostream>
#include <cmath>
#include <cassert>

auto GetSign = [](unsigned n) -> int { return (n % 2 == 0 ? 1 : -1); };

int CalculateNumberOfOntoFunc(unsigned n, unsigned m);
int CombCount(unsigned n, unsigned i);

auto main() -> int
{
    assert(CalculateNumberOfOntoFunc(6, 3) == 540);

    return 0;
}

int CalculateNumberOfOntoFunc(unsigned m, unsigned n)
{
    int result = std::pow(n, m);

    for (unsigned i = 1; i < n; i++)
    {
        result += GetSign(i) * CombCount(n, i) * std::pow(n-i, m);
    }

    return result;
}

int CombCount(unsigned n, unsigned i)
{
    if (n == 0 || i == 0)
        return 1;

    if (i > n / 2)
        i = n - i;

    int result = 1;
    for (int j = n; j >= n-i+1; j--)
    {
        result *= j;
    }
    for (int j = i; j >= 2; j--)
    {
        result /= j;
    }

    return result;
}
