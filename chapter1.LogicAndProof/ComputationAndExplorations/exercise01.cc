/*
 * exercise01.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Look for positive integers that are not the sum of the cubes
 * of nine different positive integers.
 */

#include <iostream>
#include <cmath>

/*
 * look for positive integers that are the sum of squares of four different positive integers
 */
void FindExponetiationPermutation(const int n)
{
    int max_possible_i = std::sqrt(n);
    int min_possible_i = std::sqrt(n / 4);
    for (int i = max_possible_i; i > min_possible_i; i--)
    {
        int remain = n;
        remain -= static_cast<int>(std::pow(i, 2));
        int max_possible_j = i - 1 >= std::sqrt(remain) ? std::sqrt(remain) : i - 1;
        int min_possible_j = std::sqrt(remain / 3);
        for (int j = max_possible_j; j > min_possible_j; j--)
        {
            remain -= static_cast<int>(std::pow(j, 2));
            if (remain <= 0) break;
            int max_possible_k = j - 1 >= std::sqrt(remain) ? std::sqrt(remain) : j - 1;
            int min_possible_k = std::sqrt(remain / 2);
            for (int k = max_possible_k; k > min_possible_k; k--)
            {
                remain -= static_cast<int>(std::pow(k, 2));
                if (remain <= 0) break;
                int max_possible_l = k - 1 >= std::sqrt(remain) ? std::sqrt(remain) : k - 1;
                for (int l = max_possible_l;;l--)
                {
                    if (remain == static_cast<int>(std::pow(l, 2)))
                    {
                        std::cout << "Found for " << n << std::endl;
                        std::cout << "i: " << i << " j: " << j << " k: " << k << " l: " << l << std::endl;
                        return;
                    }
                    else if (remain > static_cast<int>(std::pow(l, 2)))
                    {
                        break;
                    }
                }
            }
        }
    }
    std::cout << "Not found for " << n << std::endl;

    return;
}

int main(void)
{
    for (int i = 0; i < 1000; i++)
        FindExponetiationPermutation(i);

    return 0;
}


