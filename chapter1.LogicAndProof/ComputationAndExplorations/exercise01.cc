/*
 * exercise01.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Look for positive integers that are not the sum of the cubes
 * of nine different positive integers.
 */

#include <iostream>
#include <cmath>
#include <stack>
#include <cassert>

static const int POWER_SIZE = 3;
static const int PERM_SIZE = 9;

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
        // when both size and sum meet requirements, return
        if (permutation.size() == PERM_SIZE && StackExponetiationSum(permutation) == n)
            return permutation;
        // when stack size is full, or stack top is 1(no more element to push), stack pops
        if (permutation.size() == PERM_SIZE || next_element == 1)
        {
            popped = permutation.top();
            permutation.pop();
            has_popped = true;
        }
        // if 1 is popped, the new top is existed, also needs to be popped
        if (has_popped && popped == 1)
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
            next_element -= 1;
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
    for (int i = 1; i < 5000; i++)
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


