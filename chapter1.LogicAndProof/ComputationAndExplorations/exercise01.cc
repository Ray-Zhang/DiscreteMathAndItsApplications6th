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

const int POWER_SIZE = 3;

/*
 * look for positive integers that are the sum of squares of four different positive integers
 */
void FindExponetiationPermutation(const int n)
{
    int max_possible_i = std::pow(n, 1.0/POWER_SIZE);
    int min_possible_i = std::pow(n / 4, 1.0/ POWER_SIZE);
    for (int i = max_possible_i; i > min_possible_i; i--)
    {
        int remain = n;
        remain -= static_cast<int>(std::pow(i, POWER_SIZE));
        int max_possible_j = i - 1 >= std::pow(remain, 1.0/POWER_SIZE) ? std::pow(remain, 1.0/POWER_SIZE) : (i - 1);
        int min_possible_j = std::pow(remain / 3, 1.0/POWER_SIZE);
        for (int j = max_possible_j; j > min_possible_j; j--)
        {
            remain -= static_cast<int>(std::pow(j, POWER_SIZE));
            if (remain <= 0) break;
            int max_possible_k = j - 1 >= std::pow(remain, 1.0/POWER_SIZE) ? std::pow(remain, 1.0/POWER_SIZE) : (j - 1);
            int min_possible_k = std::pow(remain / 2, 1.0/POWER_SIZE);
            for (int k = max_possible_k; k > min_possible_k; k--)
            {
                remain -= static_cast<int>(std::pow(k, POWER_SIZE));
                if (remain <= 0) break;
                int max_possible_l = k - 1 >= std::pow(remain, 1.0/POWER_SIZE) ? std::pow(remain, 1.0/POWER_SIZE) : (k - 1);
                for (int l = max_possible_l;;l--)
                {
                    if (remain == static_cast<int>(std::pow(l, POWER_SIZE)))
                    {
                        std::cout << "Found for " << n << std::endl;
                        std::cout << "i: " << i << " j: " << j << " k: " << k << " l: " << l << std::endl;
                        return;
                    }
                    else if (remain > static_cast<int>(std::pow(l, POWER_SIZE)))
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


