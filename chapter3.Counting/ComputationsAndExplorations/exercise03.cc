/*
 * exercise03.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Verify that C(2n, n) is divisible by the square of a prime,
 * when n != 1,2 or 4, for as many positive integers n as you
 * can
 */

#include <stdlib.h>
#include <iostream>
#include <cmath>

static const int N = 14;

long long CombinationCount(int n, int r);

int main(void)
{
    for (int i = 5; i <= N; i++)
    {
        long long comb_2n_n = CombinationCount(2 * i, i);
        long long max = static_cast<long long>(std::pow(comb_2n_n, 0.5));
        for (int j = 2; j <= max; j++)
        {
            if (comb_2n_n% j == 0 && (comb_2n_n / j) % j == 0)
            {
                std::cout << "Found for " << i << ":\t" << j << " * " << j << " * " << comb_2n_n / j / j << std::endl;
                break;
            }
        }
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
