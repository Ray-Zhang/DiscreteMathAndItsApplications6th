/*
 * exercise02.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given two bit strings of length n, find the bitwise AND,
 * bitwise OR, and bitwise XOR of these strings.
 */

#include <cassert>

unsigned And(const unsigned s1, const unsigned s2);
unsigned Or(const unsigned s1, const unsigned s2);
unsigned Xor(const unsigned s1, const unsigned s2);

int main(void)
{
    unsigned s1 = 0b010101101010;
    unsigned s2 = 0b011010101010;

    assert(And(s1, s2) == 0b010000101010);
    assert(Or(s1, s2) == 0b011111101010);
    assert(Xor(s1, s2) == 0b001111000000);

    return 0;
}

unsigned And(const unsigned s1, const unsigned s2)
{
    return s1 & s2;
}

unsigned Or(const unsigned s1, const unsigned s2)
{
    return s1 | s2;
}

unsigned Xor(const unsigned s1, const unsigned s2)
{
    return s1 ^ s2;
}
