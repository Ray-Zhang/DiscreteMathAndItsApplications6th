/*
 * exercise04.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given positive integers m and n, interactively play the game
 * of Chomp
 */

#include <iostream>
#include <vector>

class Chomp
{
public:
    explicit Chomp(size_t height, size_t width): board_height(height), board_width(width), cookies(std::vector<std::vector<bool>>(board_height, std::vector<bool>(board_width, true))) { }
    void ShowBoard() const;
    void PlayStep();
    bool Finished() { return !cookies[0][0]; }
private:
    size_t board_height;
    size_t board_width;
    std::vector<std::vector<bool>> cookies;
};

void Chomp::ShowBoard() const
{
    for (int i = 0; i < board_height; i++)
    {
        for (int j = 0; j < board_width; j++)
        {
            std::cout << (cookies[i][j] ? "O" : "X");
        }
        std::cout << std::endl;
    }

    return;
}

void Chomp::PlayStep()
{
    std::cout << "Choose a cookie" << std::endl;
    size_t m, n;
    std::cin >> m >> n;
    while (m > board_height || n > board_width || !cookies[m-1][n-1])
    {
        std::cout << "No cookies there, choose another one" << std::endl;
        std::cin >> m >> n;
    }
    for (int i = m - 1; i < board_height; i++)
    {
        for (int j = n - 1; j < board_width; j++)
        {
            cookies[i][j] = false;
        }
    }

    return;
}

int main(void)
{
    // create game
    Chomp new_game(10, 8);    // initialize a game of 10 rows, 8 columns
    
    // play game until one player has won
    while (!new_game.Finished())
    {
        std::cout << "here" << std::endl;
        new_game.ShowBoard();
        new_game.PlayStep();
    }

    return 0;
}



