/*
 * exercise04.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Find as many odd integers n less than 200 as you can for
 * which C(n, floor(n/2)) is not divisible by the square of a prime.
 * Formulate a conjecture based on your evidence
 */

#include <stdlib.h>
#include <iostream>
#include <cmath>

static const int N = 200;

long long CombinationCount(int n, int r);

int main(void)
{
    for (int i = 5; i <= N; i += 2)
    {
        long long comb = CombinationCount(i, i / 2);
        long long max = static_cast<long long>(std::pow(comb, 0.5));
        for (int j = 2; j <= max; j++)
        {
            if (comb % j == 0 && (comb / j) % j == 0)
            {
                std::cout << "Found for " << i << ":\t" << j << " * " << j << " * " << comb / j / j << std::endl;
                break;
            }
        }
        std::cout << "Can't find for " << i << std::endl;
    }
    return 0;
}

long long CombinationCount(int n, int r)
{
    long long ret_val = 1;
    if (r > n)
    {
        std::cout << "Error: r is greater than n" << std::endl;
        exit(1);
    }
    if (r > n / 2)
        r = n - r;
    for (long long i = n; i > n - r; i--)
        ret_val *= i;
    for (long long i = r; i > 1; i--)
        ret_val /= i;

    return ret_val;
}
