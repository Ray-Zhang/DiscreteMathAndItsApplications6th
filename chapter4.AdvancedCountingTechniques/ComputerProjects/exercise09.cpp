/*
 * exercise09.cpp
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 * 
 * Given a positive integer n, produc e the formula for the
 * number of elements in the union of n sets
 * e.g.: N(S1||S2||S3) = N(S1) + N(S2) + N(S3) - N(S1&&S2) - N(S1&&S3) - N(S2&&S3) + N(S1&&S2&&S3)
 */

#include <iostream>
#include <string>

std::string UnionCountFormula(unsigned n);
std::string GenerateSetCountString(std::initializer_list<int> args);

std::string GenerateSetCountString(std::initializer_list<int> args)
{
    std::string result("N(");
    for (auto idx : args)
    {
        result += "S" + std::to_string(idx);
    }
    result += ")";
    return result;
};

auto main() -> int
{
    std::cout << GenerateSetCountString({1,2,3}) << std::endl;
    return 0;
}

