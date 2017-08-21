/*
 * exercise04.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given a function f from {1,2,...,n} to itself,
 * determine whether f is onto.
 */

#include <cassert>
#include <set>
#include <iostream>

using F = unsigned (*)(unsigned);

/*
 * An onto function on {1,2,...,n} example
 */
unsigned Abs(unsigned x)
{
    return (x >= 0 ? x : -x);
}

/*
 * A non-onto function example
 */
unsigned IntegerDivision(unsigned x)
{
    return x / 10;
}

/*
 * check if the input function is a one-to-one function
 * when both f's domain and codomain are {1, 2, ..., 100}
 * Since domain and codomain have the same number of elements,
 * if f is onto is equivelent to f is one-to-one
 */
bool IsOnToFunction(F f)
{
    std::set<int> image_set({});
    for (int i = 1; i < 101; i++)
    {
        int image = f(i);
        if (image_set.find(image) == image_set.end())
            image_set.insert(image);
        else
            return false;
    }
    return true;
}

int main(void)
{
    assert(IsOnToFunction(Abs));
    assert(!IsOnToFunction(IntegerDivision));

    return 0;
}


