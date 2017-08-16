/*
 * exercise02.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Give multisets A and B from the same universal set, find
 * union of A and B, intersection of A and B, A minus B,
 * and A plus B
 */

#include <cassert>
#include <set>
#include "SetHelper.h"

int main(void)
{
    std::multiset<char> A({}), B({});
    A.insert('a');
    A.insert('a');
    A.insert('a');
    A.insert('b');
    A.insert('b');
    A.insert('c');
    B.insert('a');
    B.insert('a');
    B.insert('b');
    B.insert('b');
    B.insert('b');
    B.insert('d');
    B.insert('d');
    B.insert('d');
    B.insert('d');
    std::multiset<char> output;
    MultiSetUnion(output, A, B);
    assert(output == std::multiset<char>({'a','a','a','b','b','b','c','d','d','d','d'}));
    MultiSetIntersection(output, A, B);
    assert(output == std::multiset<char>({'a', 'a', 'b', 'b'}));
    MultiSetSubtract(output, A, B);
    assert(output == std::multiset<char>({'a', 'c'}));

    return 0;
}



