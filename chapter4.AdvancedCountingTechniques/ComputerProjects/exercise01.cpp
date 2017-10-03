/*
 * exercise01.cpp
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given a positive interger n, list all the moves required
 * in the Tower of Hanoi puzzle to move n disks
 * from one peg to another according to the rules of the puzzle.
 */

#include <iostream>

void HanoiRecursive(int n, int from, int to, int other);

int main(void)
{
    std::cout << "One disk" << std::endl;
    HanoiRecursive(1, 1, 3, 2);
    std::cout << "Two disk" << std::endl;
    HanoiRecursive(2, 1, 3, 2);
    std::cout << "Three disk" << std::endl;
    HanoiRecursive(3, 1, 3, 2);
    std::cout << "Four disk" << std::endl;
    HanoiRecursive(4, 1, 3, 2);

    return 0;
}

void HanoiRecursive(int n, int from, int to, int other)
{
    if ( n > 1 )
    {
        HanoiRecursive(n - 1, from, other, to);
        std::cout << "Move " << n << " from " << from << " to " << to << std::endl;
        HanoiRecursive(n - 1, other, to, from);
    }
    else
    {
        std::cout << "Move " << n << " from " << from << " to " << to << std::endl;
    }
}
