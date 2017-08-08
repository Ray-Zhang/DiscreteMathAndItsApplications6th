/*
 * exercise01.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 * 
 * Given the truth values of the propositions p and q, find the
 * truth value of the conjunction, disjunction, exclusive or, 
 * conditional statement, and biconditional of these propositions
 */

#include <iostream>
#include <cassert>

bool Conjunction(const bool p, const bool q);
bool Disjunction(const bool p, const bool q);
bool ExclusiveOr(const bool p, const bool q);
bool Conditional(const bool p, const bool q);
bool Biconditional(const bool p, const bool q);

int main(void) {
    // Test
    // Conjunction
    assert(Conjunction(true, true));
    assert(!Conjunction(true, false));
    assert(!Conjunction(false, true));
    assert(!Conjunction(false, false));
    // Disjunction
    assert(Disjunction(true, true));
    assert(Disjunction(true, false));
    assert(Disjunction(false, true));
    assert(!Disjunction(false, false));
    // ExclusiveOr
    assert(!ExclusiveOr(true, true));
    assert(ExclusiveOr(true, false));
    assert(ExclusiveOr(false, true));
    assert(!ExclusiveOr(false, false));
    // Conditional
    assert(Conditional(true, true));
    assert(!Conditional(true, false));
    assert(Conditional(false, true));
    assert(Conditional(false, false));
    // Biconditional
    assert(Biconditional(true, true));
    assert(!Biconditional(true, false));
    assert(!Biconditional(false, true));
    assert(Biconditional(false, false));
    return 0;
}

bool Conjunction(const bool p, const bool q)
{
    return p && q;
}

bool Disjunction(const bool p, const bool q)
{
    return p || q;
}

bool ExclusiveOr(const bool p, const bool q)
{
    return p ^ q;
}

bool Conditional(const bool p, const bool q)
{
    return !p || q;
}

bool Biconditional(const bool p, const bool q)
{
    return p == q;
}
