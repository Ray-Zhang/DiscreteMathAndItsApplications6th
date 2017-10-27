/*
 * exercise07.cpp
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given a recurrence relation of the form f(n) = af(n/b) +
 * c, where a is a real number, b is a positive integer, and c
 * is a real number, and a positive integer k, find f(b**k) using
 * iteration
 */
#include <iostream>
#include <tuple>

using FCostType = std::tuple<long double, long double>;

class RecurrenceRelation
{
public:
    RecurrenceRelation(long double _a, int _b, long double _c):a(_a), b(_b), c(_c) {  b == (b <= 0 ? 1 : b); }
    const FCostType GetCountAsFOne(long double n) const;
private:
    // f(n) = af(n/b) + c
    long double a;
    int b;
    long double c;
};

auto main() -> int
{
    RecurrenceRelation rr(2.0, 2, 1.0);
    FCostType fct = rr.GetCountAsFOne(16);
    std::cout << std::get<0>(fct) << "f(1) + " << std::get<1>(fct) << std::endl;

    return 0;
}

const FCostType RecurrenceRelation::GetCountAsFOne(long double n) const
{
    FCostType result = std::make_tuple(1.0, 0.0);
    while (n > 1)
    {
        n /= b;
        std::get<1>(result) += std::get<0>(result) * c;
        std::get<0>(result) *= a;
    }

    return result;
}
