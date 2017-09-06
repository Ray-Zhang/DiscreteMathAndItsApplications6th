/*
 * exercise07.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given a positive integer n and a nonnegative integer r
 * not exceeding n, list all the r-permutations of the set
 * {1,2,3,...,n} in lexicographic order
 */

#include <algorithm>
#include <iostream>
#include <vector>

bool NextPermutation(std::vector<int> &perm);
static const int N = 5;

int main(void)
{
    std::vector<int> test_normal_case({1,2,3,4});
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
        while ((perm.cbegin() + i) != std::find(perm.cbegin(), perm.cbegin() + i, new_val))
        {
            new_val++;
        }
        if (new_val <= N)
        {
            perm[i] = new_val;
            for (int j = i + 1; j < perm.size(); j++)
            {
                new_val = 1;
                while ((perm.cbegin() + j) != std::find(perm.cbegin(), perm.cbegin() + j, new_val))
                {
                    new_val++;
                }
                perm[j] = new_val;
            }
            return true;
        }
    }

    return false;
}
