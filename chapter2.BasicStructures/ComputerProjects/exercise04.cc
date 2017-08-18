/*
 * exercise04.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given a function f from {1, 2, ... , n} to the set of integers,
 * determine whether f is one-to-one
 */

#include <cassert>
#include <set>
#include <iostream>

using F = int (*)(unsigned);

/*
 * A one-to-one function example
 */
int Square(unsigned x)
{
    return x * x;
}

/*
 * A non-one-to-one function example
 */
int IntegerDivision(unsigned x)
{
    return x / 10;
}

/*
 * check if the input function is a one-to-one function
 * when f's domain is {1, 2, ..., 100}, codomain is the set of integers
 */
bool IsOneToOneFunction(F f)
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
    assert(IsOneToOneFunction(Square));
    assert(!IsOneToOneFunction(IntegerDivision));

    return 0;
}


