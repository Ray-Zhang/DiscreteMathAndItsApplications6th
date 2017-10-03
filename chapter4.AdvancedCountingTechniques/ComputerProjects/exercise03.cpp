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
#include <iostream>
#include <cassert>
#include <string>

using BitsSet = std::set<std::string>;
void UpdateBitsSet(BitsSet &bits_set_n_minus1, BitsSet &bits_set_n_minus2);

int main(void)
{
    BitsSet bits_set_n_minus1({"10", "01", "11"});
    BitsSet bits_set_n_minus2({"0", "1"});

    for (int i = 3; i < 10; i++)
    {
        UpdateBitsSet(bits_set_n_minus1, bits_set_n_minus2);
    }
    for (const auto &item : bits_set_n_minus2)
    {
        std::cout << item << std::endl;
    }

    return 0;
}

void UpdateBitsSet(BitsSet &bits_set_n_minus1, BitsSet &bits_set_n_minus2)
{
    BitsSet next({});
    for (const auto &item : bits_set_n_minus1)
    {
        next.insert(item + "1");
    }
    for (const auto &item : bits_set_n_minus2)
    {
        next.insert(item + "10");
    }
    bits_set_n_minus2 = bits_set_n_minus1;
    bits_set_n_minus1 = next;
}
