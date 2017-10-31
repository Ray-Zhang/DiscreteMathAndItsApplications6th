/*
 * exercise03.h
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef EXERCISE03_H
#define EXERCISE03_H

#include <set>
#include <string>
#include <vector>

class BitSequences;

using SequenceSet = std::set<std::string>;
using BitSequenceVector = std::vector<BitSequences*>;


class BitSequencesFactory
{
    friend class BitSequences;
public:
    static BitSequences* GetBitSequences(size_t n);
private:
    static size_t max_n;
    static BitSequenceVector bit_seq_vector;
};

class BitSequences
{
    friend class BitSequencesFactory;
public:
    BitSequences(BitSequences &bs) = delete;
    BitSequences() = delete;
    BitSequences& operator=(BitSequences &bs) = delete;
    SequenceSet& GetSequenceSet() { return all_sequences_of_nbits; }
private:
    BitSequences(size_t n);
    SequenceSet all_sequences_of_nbits;
};

#endif /* !EXERCISE03_H */
