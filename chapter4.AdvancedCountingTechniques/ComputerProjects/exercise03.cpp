/*
 * exercise03.cpp
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given a positive integer n, list all the bit sequences of
 * length n that do not have a pair of consecutive 0s.
 */

#include <set>
#include <string>
#include <vector>
#include "exercise03.h"

BitSequences::BitSequences(size_t n)
{
    if (n > 2)
    {
        all_sequences_of_nbits = {};
        for (const auto &item : (BitSequencesFactory::bit_seq_vector[n-2])->all_sequences_of_nbits)
        {
            all_sequences_of_nbits.insert(item + "1");
        }
        for (const auto &item : (BitSequencesFactory::bit_seq_vector[n-3])->all_sequences_of_nbits)
        {
            all_sequences_of_nbits.insert(item + "10");
        }
    }
    else if (n == 1)
    {
        all_sequences_of_nbits = {"0", "1"};
    }
    else
    {
        all_sequences_of_nbits = {"01", "11", "10"};
    }
}

BitSequenceVector BitSequencesFactory::bit_seq_vector({new BitSequences(1), new BitSequences(2)});

size_t BitSequencesFactory::max_n = 2;

BitSequences* BitSequencesFactory::GetBitSequences(size_t n)
{
    if (n <= max_n)
    {
        return bit_seq_vector[n-1];
    }
    else
    {
        for (int i = max_n + 1; i <= n; i++)
        {
            bit_seq_vector.push_back(new BitSequences(i));
        }
        return bit_seq_vector[n-1];
    }
}

