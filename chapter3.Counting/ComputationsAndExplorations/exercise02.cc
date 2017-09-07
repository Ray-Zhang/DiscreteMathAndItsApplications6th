/*
 * exercise02.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Which binomial coefficients are odd? Can you formulate
 * a conjecture based on numerical evidence?
 */

#include <iostream>
#include <stdlib.h>

long long CombinationCount(int n, int r);
static const int N = 20;

int main(void)
{
    for (int i = 1; i < N; i++)
    {
        std::cout << "N = " << i << ":\t";
        for (int j = 0; j <= i; j++)
        {
            std::cout << CombinationCount(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

long long CombinationCount(int n, int r)
{
    long long ret_val = 1;
    if (r > n / 2)
        r = n - r;
    if (r > n)
    {
        std::cout << "Error: r is greater than n" << std::endl;
        exit(1);
    }
    for (long long i = n; i > n - r; i--)
        ret_val *= i;
    for (long long i = r; i > 1; i--)
        ret_val /= i;

    return ret_val;
}


