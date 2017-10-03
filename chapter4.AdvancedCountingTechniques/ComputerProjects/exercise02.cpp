/*
 * exercise02.cpp
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given a positive interger n and an integer k with 1 <= k <= n,
 * list all the moves used by the Frame-Stewart algorithm
 * to move n disks from one peg to another using four pegs
 * according the rules of the puzzle
 */

#include <iostream>
#include <cmath>

void HanoiRecursive(int n, int from, int to, int other, int print_base);
void FrameStewartHanoi(int n, int from, int to, int other_occupy, int other_none, int print_base);
int GetK(int n);    // k is the value that makes (k-1)k/2 < n <= k(k+1)/2

int main(void)
{
    std::cout << "One disk" << std::endl;
    FrameStewartHanoi(1, 1, 4, 2, 3, 0);
    std::cout << "Two disks" << std::endl;
    FrameStewartHanoi(2, 1, 4, 2, 3, 0);
    std::cout << "Three disks" << std::endl;
    FrameStewartHanoi(3, 1, 4, 2, 3, 0);
    std::cout << "Four disks" << std::endl;
    FrameStewartHanoi(4, 1, 4, 2, 3, 0);
    std::cout << "Five disks" << std::endl;
    FrameStewartHanoi(5, 1, 4, 2, 3, 0);
}


void HanoiRecursive(int n, int from, int to, int other, int print_base)
{
    if ( n > 1 )
    {
        HanoiRecursive(n - 1, from, other, to, print_base);
        std::cout << "Move " << n + print_base << " from " << from << " to " << to << std::endl;
        HanoiRecursive(n - 1, other, to, from, print_base);
    }
    else
    {
        std::cout << "Move " << n + print_base << " from " << from << " to " << to << std::endl;
    }
}

void FrameStewartHanoi(int n, int from, int to, int other_occupy, int other_none, int print_base)
{
    if ( n > 1)
    {
        int k = GetK(n);
        if ( k < n)
        {
            FrameStewartHanoi(n - k, from, other_occupy, to, other_none, print_base);
            HanoiRecursive(k, from, to, other_none, print_base + (n - k) );
            FrameStewartHanoi(n - k, other_occupy, to, from, other_none, print_base);
        }
        else
        {
            HanoiRecursive(k, from, to, other_none, print_base);
        }
    }
    else
    {
        std::cout << "Move " << n + print_base << " from " << from << " to " << to << std::endl;
    }

    return;
}

int GetK(int n)
{
    double k_up_limit = 0.5 + std::sqrt( 2 * n + 0.25);
    return static_cast<int>(std::floor(k_up_limit));
}
