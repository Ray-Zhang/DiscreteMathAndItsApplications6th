/*
 * exercise05.cpp
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given a recurrence relation An = C1*A(n-1) + C2*A(n-2), wher
 * C1 and C2 are real numbers, initial conditions A0 = C0 and
 * A1 = C1, and a positive integer k, find Ak using iteration.
 */

#include <iostream>

const static float C_ZERO = 34.56f;
const static float C_ONE = 4.6f;
const static float C_Two = 2.2f;

float CalculateKRecurrence(unsigned k);

auto main() -> int
{
    for (int i = 1; i < 10; i++)
    {
        std::cout << CalculateKRecurrence(i) << std::endl;
    }

    return 0;
}

float CalculateKRecurrence(unsigned k)
{
    float result = 0.0f;
    if (k <= 1)
    {
        result = C_ONE;
    }
    else
    {
        float a_n_2 = C_ZERO;
        float a_n_1 = C_ONE;
        float next = result;
        for (int i = 2; i <= k; i++)
        {
            next = C_ONE * a_n_1 + C_Two * a_n_2;
            a_n_2 = a_n_1;
            a_n_1 = next;
        }
        result = next;
    }

    return result;
}
