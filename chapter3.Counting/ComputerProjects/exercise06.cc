/*
 * exercise06.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given a positive integer n and a nonnegative integer r
 * not exceeding n, list all the r-combinations of the set
 * {1,2,3,...,n} in lexicographic order.
 */

#include <iostream>
#include <vector>
#include <algorithm>

static const int N = 5;

bool NextCombination(std::vector<int> &comb);

int main(void)
{
    std::vector<int> test_normal_case({1,2,3});
    while (NextCombination(test_normal_case))
    {
        for (auto item : test_normal_case)
        {
            std::cout << item;
        }
        std::cout << std::endl;
    }

    return 0;
}

/*
 * return true if next combination exists, false otherwise
 */
bool NextCombination(std::vector<int> &comb)
{
    for (int i = comb.size() - 1; i >= 0; i--)
    {
        if (comb[i] != (N - (comb.size() - i - 1)))
        {
            // increase comb[i] by 1
            comb[i] += 1;
            // set all following items sequentially increasing after comb[i]
            for (int j = i + 1; j < comb.size(); j++)
            {
                comb[j] = comb[i] + (j - i);
            }
            return true;
        }
    }
    return false;
}

