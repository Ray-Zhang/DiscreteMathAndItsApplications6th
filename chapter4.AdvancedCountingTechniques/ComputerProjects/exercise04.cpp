/*
 * exercise04.cpp
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given a positive integer n, write out all ways to parenthesize
 * the product of n + 1 variable.
 */
#include <iostream>
#include <string>
#include <vector>

using ParenthesisCombinations = std::vector<std::string>;
ParenthesisCombinations ListParenthesisCombination(unsigned n);

auto main() -> int
{
    ParenthesisCombinations pc = ListParenthesisCombination(6);
    for (auto item : pc)
    {
        std::cout << item << std::endl;
    }

    return 0;
}

ParenthesisCombinations ListParenthesisCombination(unsigned n)
{
    ParenthesisCombinations result({});
    if (n > 2)
    {
        for (int i = 1; i < n; i++)
        {
            ParenthesisCombinations FirstVector = ListParenthesisCombination(i);
            ParenthesisCombinations SecondVector = ListParenthesisCombination(n - i);
            for (auto item1 : FirstVector)
            {
                for (auto item2 : SecondVector)
                {
                    result.emplace_back("(" + item1 + item2 + ")");
                }
            }
        }
    }
    else if (n == 2)
    {
        result.emplace_back("(*)");
    }
    else
    {
        result.emplace_back("*");
    }

    return result;
}
