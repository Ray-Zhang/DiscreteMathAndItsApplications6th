/*
 * exercise04.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given an equation x1 + x2 + ... + xn = C, where C is a
 * constant, and x1, x2, ..., xn are nonnegative integers, list
 * all the solutions.
 */

#include <iostream>
#include <cmath>
#include <stack>
#include <cassert>

static const int POWER_SIZE = 1;
static const int STACK_MAX_ITEM = 5;

int StackExponetiationSum(std::stack<int> permutation);
void PrintOutStack(std::stack<int> permutation);

void FindExponetiationPermutationStack(const int n)
{
    std::stack<int> permutation;
    int permutation_counts = 0;
    int remain = n;
    int max_possible = std::pow(n, 1.0/POWER_SIZE);
    int next_element = max_possible;
    int popped;
    while (true)
    {
        bool has_popped = false;
        permutation.push(next_element);
        int sum = StackExponetiationSum(permutation);
        // when both size and sum meet requirements, print out
        if (sum == n)
        {
            std::cout << "Found one permutation for :" << n << std::endl;
            permutation_counts++;
            PrintOutStack(permutation);
            // pop to continue finding other permutation
            popped = permutation.top();
            permutation.pop();
            has_popped = true;
        }
        // when sum is greater than n or stack is full, stack pops
        if (sum > n || permutation.size() == STACK_MAX_ITEM)
        {
            popped = permutation.top();
            permutation.pop();
            has_popped = true;
        }
        // if 1 is popped, the new top is exhausted, also needs to be popped
        // when there's no more element to pop, search failed
        while (has_popped && popped == 1)
        {
            if (permutation.empty()) return;
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

void PrintOutStack(std::stack<int> permutation)
{
    int count = 0;
    while (!permutation.empty())
    {
        std::cout << permutation.top() << std::endl;
        permutation.pop();
        count++;
    }
    for (;count < STACK_MAX_ITEM; count++)
    {
        std::cout << 0 << std::endl;
    }
}

int main(void)
{
    for (int i = 1; i < 100; i++)
    {
        std::cout << i << "'s result" << std::endl;
        FindExponetiationPermutationStack(i);
    }

    return 0;
}


