/*
 * exercise05.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given a positive integer n, list all the permutations of the
 * set {1,2,3,...,n} in lexicographic order.
 */

#include <algorithm>
#include <iostream>
#include <vector>

bool NextPermutation(std::vector<int> &perm);
int SmallestElementLargerThan(const std::vector<int> &arr, int start, int base);
void ExchangeTwoElements(std::vector<int> &arr, int idx_a, int idx_b);

int main(void)
{
    std::vector<int> test_normal_case({1,2,3,4,5});
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
    for (int i = perm.size() - 1; i >= 1; i--)
    {
        if (perm[i] > perm[i-1])
        {
            // find smallest element after i-1 greater than perm[i-1]
            int found_idx = SmallestElementLargerThan(perm, i, perm[i-1]);

            // place the found element in perm[i-1]
            ExchangeTwoElements(perm, i - 1, found_idx);

            // sort elements from i to end
            std::sort(perm.begin() + i, perm.end());

            return true;
        }
    }

    return false;
}

int SmallestElementLargerThan(const std::vector<int> &arr, int start, int base)
{
    size_t ret_val = start;
    for (int i = start; i < arr.size(); i++)
    {
        if (arr[i] > base && arr[ret_val] > arr[i])
        {
            ret_val = i;
        }
    }

    return ret_val;
}

void ExchangeTwoElements(std::vector<int> &arr, int idx_a, int idx_b)
{
    int temp = arr[idx_a];
    arr[idx_a] = arr[idx_b];
    arr[idx_b] = temp;

    return;
}
