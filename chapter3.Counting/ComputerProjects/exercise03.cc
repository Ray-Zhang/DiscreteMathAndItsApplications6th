/*
 * exercise03.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given a sequence of positive integers, find the longest in-
 * creasing and the longest decreasing subsequence of the
 * sequence.
 */

#include <vector>
#include "SetHelper.h"
#include <cassert>
#include <iostream>

using Comp = bool (*)(unsigned,unsigned);

bool Greater(unsigned a, unsigned b)
{
    return a >= b;
}

bool Lesser(unsigned a, unsigned b)
{
    return a <= b;
}

void LongestSubsequence(std::vector<unsigned> &output, std::vector<unsigned> &sequence, Comp comp);

int main(void)
{
    std::vector<unsigned> test_normal_case({1,3,5,2,4,6,7,8,0,9});
    std::vector<unsigned> output({});
    LongestSubsequence(output, test_normal_case, Greater);
    assert(output == std::vector<unsigned>({2,4,6,7,8}));
    LongestSubsequence(output, test_normal_case, Lesser);
    assert(output == std::vector<unsigned>({5,2}));

    return 0;
}

void LongestSubsequence(std::vector<unsigned> &output, std::vector<unsigned> &sequence, Comp comp)
{
    output.clear();
    unsigned length_longest_subsequence = 1;
    auto iter_longest_subsequence = sequence.cbegin();
    unsigned length_current_subsequence = 1;
    for (auto iter = sequence.cbegin() + 1; iter != sequence.cend(); iter++)
    {
        if (comp(*iter, *(iter - 1)))
        {
            length_current_subsequence++;
        }
        else
        {
            if (length_current_subsequence > length_longest_subsequence)
            {
                length_longest_subsequence = length_current_subsequence;
                iter_longest_subsequence = iter - length_longest_subsequence;    // set start iter to new subsequence
                length_current_subsequence = 1;
            }
        }
    }
    output = std::vector<unsigned>(iter_longest_subsequence, iter_longest_subsequence + length_longest_subsequence);

    return;
}
