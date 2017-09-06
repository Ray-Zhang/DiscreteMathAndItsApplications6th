/*
 * exercise10.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given positive integers n and r, list all the r-combinations,
 * with repetition allowed, of the set {1,2,3,...,n}.
 */

#include <iostream>
#include <vector>
#include <algorithm>

static const int N = 5;

bool NextCombination(std::vector<int> &comb);

int main(void)
{
    std::vector<int> test_normal_case(4, 1);
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
            // set all following items to 1
            std::transform(comb.begin() + i + 1, comb.end(), comb.begin() + i + 1, [](int item) -> int { return 1; });
            return true;
        }
    }
    return false;
}

