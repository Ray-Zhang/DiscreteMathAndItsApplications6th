/*
 * exercise01.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Find the number of possible outcomes in a two-team play-
 * off when the winner is the first team to win 5 out of 9, 6
 * out of 11, 7 out of 13, and 8 out of 15
 */

#include <iostream>
#include <set>
#include <utility>

static const int N = 5;
using Result = std::pair<int, int>;

void GetFinalResults(std::set<Result> &output, const std::set<Result> &orig);

int main(void)
{
    std::set<Result> match_init({std::make_pair(0, 0)});
    std::set<Result> final_results({});
    GetFinalResults(final_results, match_init);
    for (auto match_result : final_results)
    {
        std::cout << match_result.first << ":" << match_result.second << std::endl;
    }
}

void GetFinalResults(std::set<Result> &output, const std::set<Result> &orig)
{
    std::set<Result> match_progress(orig);    // make a copy before any further match starts
    while (match_progress.size() > 0)
    {
        for (auto match_status : match_progress)
        {
            if (match_status.first + 1 == N)
            {
                output.insert(std::make_pair(match_status.first + 1, match_status.second));
            }
            else
            {
                match_progress.insert(std::make_pair(match_status.first + 1, match_status.second));
            }
            if (match_status.second + 1 == N)
            {
                output.insert(std::make_pair(match_status.first, match_status.second + 1));
            }
            else
            {
                match_progress.insert(std::make_pair(match_status.first, match_status.second + 1));
            }
            match_progress.erase(match_status);
        }
    }

    return;
}
