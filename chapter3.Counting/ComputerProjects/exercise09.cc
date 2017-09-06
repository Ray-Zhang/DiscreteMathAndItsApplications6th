/*
 * exercise09.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given positive integers n and r, list all the
 * r-permutations, with repetition allowed, of the set
 * {1,2,3,...,n}.
 */

#include <algorithm>
#include <iostream>
#include <vector>

bool NextPermutation(std::vector<int> &perm);
static const int N = 5;

int main(void)
{
    std::vector<int> test_normal_case({1,1,1,1,1,1});
    while (NextPermutation(test_normal_case))
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
 * true is next lexicographic permutation exists, false otherwise
 */
bool NextPermutation(std::vector<int> &perm)
{
    for (int i = perm.size() - 1; i >= 0; i--)
    {
        int new_val = perm[i] + 1;
        if (new_val <= N)
        {
            perm[i] = new_val;
            std::transform(perm.begin() + i + 1, perm.end(), perm.begin() + i + 1,
                    [](int x) -> int { return 1; });
            return true;
        }
    }

    return false;
}
