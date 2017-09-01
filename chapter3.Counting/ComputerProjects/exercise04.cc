/*
 * exercise04.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given an equation x1 + x2 + ... + xn = C, where C is a 
 * constant, and x1, x2, ... , xn are nonnegative integers, list
 * all the solutions
 */

#include <iostream>
#include <cmath>
#include <stack>
#include <cassert>

static const int POWER_SIZE = 1;
static const int PERM_SIZE = 4;
static const int TEST_START = 10;

int StackExponetiationSum(std::stack<int> permutation);

std::stack<int> FindExponetiationPermutationStack(const int n)
{
    std::stack<int> permutation;
    int remain = n;
    int max_possible = std::pow(n, 1.0/POWER_SIZE);
    int next_element = max_possible;
    int popped;
    while (true)
    {
        bool has_popped = false;
        permutation.push(next_element);
        int sum = StackExponetiationSum(permutation);
        // when both size and sum meet requirements, return
        if (permutation.size() == PERM_SIZE && sum == n)
            return permutation;
        // when sum is greater or equal to n, stack pops
        if (sum >= n)
        {
            popped = permutation.top();
            permutation.pop();
            has_popped = true;
        }
        // when stack size is full, stack pops
        if (permutation.size() == PERM_SIZE)
        {
            popped = permutation.top();
            permutation.pop();
            has_popped = true;
        }
        // if 1 is popped, the new top is exhausted, also needs to be popped
        // when there's no more element to pop, search failed
        while (has_popped && popped == 1)
        {
            if (permutation.empty()) return permutation;
            popped = permutation.top();
            permutation.pop();
            has_popped = true;
        }
        // calculate next element
        if (has_popped)
            next_element = popped - 1;
        else
        {
            sum = StackExponetiationSum(permutation);
            next_element = std::pow(n - sum, 1.0/POWER_SIZE) > next_element ? next_element : (std::pow(n - sum, 1.0/POWER_SIZE));
        }
        if (next_element <= 0)
            next_element = 1;
    }
}

int StackExponetiationSum(std::stack<int> permutation)
{
    int sum = 0;
    while (!permutation.empty())
    {
        int top = permutation.top();
        sum += std::pow(top, POWER_SIZE);
        permutation.pop();
    }
    return sum;
}

int main(void)
{
    // find exponetiation permutation, stack method test
    for (int i = TEST_START; i < 50; i++)
    {
        std::stack<int> perm = FindExponetiationPermutationStack(i);
        if (perm.empty())
            std::cout << "Can't find for " << i << std::endl;
        else
        {
            std::cout << "Found for i: " << i << std::endl;
            while (!perm.empty())
            {
                std::cout << perm.top() << std::endl;
                perm.pop();
            }
        }
    }

    return 0;
}

