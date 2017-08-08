/*
 * exercise03.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given the truth values of the propositions p and q in fuzzy
 * logic, find the truth value of the disjunction and the conjunction
 * of p and q
 */

#include <cassert>

// class forward declaration
class FuzzyBoolean;

// functions forward declaration
FuzzyBoolean And(const FuzzyBoolean &p, const FuzzyBoolean &q);
FuzzyBoolean Or(const FuzzyBoolean &p, const FuzzyBoolean &q);

class FuzzyBoolean
{
    friend FuzzyBoolean And(const FuzzyBoolean &p, const FuzzyBoolean &q);
    friend FuzzyBoolean Or(const FuzzyBoolean &p, const FuzzyBoolean &q);
public:
    bool operator==(const FuzzyBoolean &p);
    bool operator!=(const FuzzyBoolean &p);
    explicit FuzzyBoolean(float init);
private:
    float value;
};

inline bool FuzzyBoolean::operator==(const FuzzyBoolean &p)
{
    return value == p.value;
}

inline bool FuzzyBoolean::operator!=(const FuzzyBoolean &p)
{
    return !(*this == p);
}

FuzzyBoolean And(const FuzzyBoolean &p, const FuzzyBoolean &q)
{
    if (p.value <= q.value)
        return FuzzyBoolean(p.value);
    else
        return FuzzyBoolean(q.value);
}

FuzzyBoolean Or(const FuzzyBoolean &p, const FuzzyBoolean &q)
{
    if (p.value >= q.value)
        return FuzzyBoolean(p.value);
    else
        return FuzzyBoolean(q.value);
}

FuzzyBoolean::FuzzyBoolean(float init)
{
    if (init > 1)
        value = 1;    // any value greater than 1 is treated as 1
    else if (init < 0)
        value = 0;    // any value less than 0 is treated as 0
    else
        value = init;
}

int main(void)
{
    // constructor test
    assert(FuzzyBoolean(-1.0) == FuzzyBoolean(0.0));
    assert(FuzzyBoolean(10) == FuzzyBoolean(1.0));

    // AND, OR function test
    assert(And(FuzzyBoolean(0.2), FuzzyBoolean(0.8)) == FuzzyBoolean(0.2));
    assert(Or(FuzzyBoolean(0.2), FuzzyBoolean(0.8)) == FuzzyBoolean(0.8));

    return 0;
}



