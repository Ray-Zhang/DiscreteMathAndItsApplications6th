/*
 * exercise06.cpp
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given a recurrence relation An = C1*A(n-1) + C2*A(n-2), wher
 * C1 and C2 are real numbers, initial conditions A0 = C0 and
 * A1 = C1, determine the unique solution.
 */

// TODO: resolve unique solution based on roots, require linear algebra knowledge

#include <iostream>
#include <tuple>
#include <limits>
#include <cmath>

const static float C_ZERO = 3.0f;
const static float C_ONE = 2.0f;
const static float C_Two = -1.0f;

auto CalculateDiscriminant = [](long double a, long double b, long double c) -> long double { return b * b - 4 * a * c; };
using RootType = std::tuple<long double, long double>;
bool CalculateRoots(RootType &roots, long double a, long double b, long double c);

auto main() -> int
{
    RootType roots({});
    if (CalculateRoots(roots, 1, -2, 1))
    {
        // calculation for solution
    }
    else
    {
        // calculation for solution
    }

    return 0;
}

/*
 * return value: true: two equal roots
 *              false: two different roots
 */
bool CalculateRoots(RootType &roots, long double a, long double b, long double c)
{
    long double discriminant = CalculateDiscriminant(a, b, c);
    long double axis = -b / (2 * a);
    if (discriminant < std::numeric_limits<long double>::epsilon())    // two equal roots
    {
        roots = std::make_tuple(axis, axis);
        return true;
    }
    else    // two different roots
    {
        roots = std::make_tuple(axis + std::sqrt(discriminant) / (2 * a), axis - std::sqrt(discriminant));
        return false;
    }
}
