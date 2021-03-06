/*
 * SetHelper.h
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given subsets A and B of a set with n elements,
 * use bit strings to find A's complement, union
 * of A and B, and intersection of A and B
 */

#include <set>
#include <string>
#include <iostream>
#include <map>
#include <iostream>
#include <utility>
#include <cmath>

#ifndef _SETHELPER_H
#define _SETHELPER_H
template <typename T>
std::string SetToBinaryString(const std::set<T> &universal_set, const std::set<T> &original_set)
{
    std::string ret_value("");
    for (auto elem: universal_set)
    {
        if (original_set.find(elem) == original_set.end())
            ret_value += "0";
        else
            ret_value += "1";
    }

    return ret_value;
}

template <typename T>
void BinaryStringToSet(std::set<T> &ret_set, const std::set<T> &universal, const std::string &set_string)
{
    if (universal.size() != set_string.size())
        return;
    ret_set.clear();
    int i = 0;
    for (auto elem : universal)
    {
        if (set_string[i++] == '1')
            ret_set.insert(elem);
    }
}

std::string Complement(const std::string &original_set);

std::string Union(const std::string &original_set_a, const std::string &original_set_b);

std::string Intersection(const std::string &original_set_a, const std::string &original_set_b);

template <typename T>
void AddMultiElemToSet(std::multiset<T> &ret_set, const std::size_t elem_size, const T &elem)
{
    for (int i = 0; i < elem_size; i++)
    {
        ret_set.insert(elem);
    }

    return;
}

template <typename T>
void MultiSetUnion(std::multiset<T> &ret_set, const std::multiset<T> &original_multiset_a, const std::multiset<T> &original_multiset_b)
{
    ret_set.clear();
    // Iterate all unique elements in multiset a
    for (auto unique_elem = original_multiset_a.cbegin(); unique_elem != original_multiset_a.cend(); unique_elem = original_multiset_a.upper_bound(*unique_elem))
    {
        if (original_multiset_a.count(*unique_elem) >= original_multiset_b.count(*unique_elem))
        {
            std::size_t elem_size = original_multiset_a.count(*unique_elem);
            AddMultiElemToSet(ret_set, elem_size, *unique_elem);
        }
        else
        {
            std::size_t elem_size = original_multiset_b.count(*unique_elem);
            AddMultiElemToSet(ret_set, elem_size, *unique_elem);
        }
    }
    // Iterate all unique elements in multise b, ignore any element already put into ret_set
    for (auto unique_elem = original_multiset_b.cbegin(); unique_elem != original_multiset_b.cend(); unique_elem = original_multiset_b.upper_bound(*unique_elem))
    {
        if (ret_set.find(*unique_elem) != ret_set.cend())    // element already exists
            continue;
        else
        {
            std::size_t elem_size = original_multiset_b.count(*unique_elem);
            AddMultiElemToSet(ret_set, elem_size, *unique_elem);
        }
    }
    return;
}

template <typename T>
void MultiSetIntersection(std::multiset<T> &ret_set, const std::multiset<T> &original_multiset_a, const std::multiset<T> &original_multiset_b)
{
    ret_set.clear();
    // Iterate all unique elements in multiset a, the other multiset doesn't need to be scanned
    for (auto unique_elem = original_multiset_a.cbegin(); unique_elem != original_multiset_a.cend(); unique_elem = original_multiset_a.upper_bound(*unique_elem))
    {
        if (original_multiset_a.count(*unique_elem) <= original_multiset_b.count(*unique_elem))
        {
            std::size_t elem_size = original_multiset_a.count(*unique_elem);
            AddMultiElemToSet(ret_set, elem_size, *unique_elem);
        }
        else
        {
            std::size_t elem_size = original_multiset_b.count(*unique_elem);
            AddMultiElemToSet(ret_set, elem_size, *unique_elem);
        }
    }
    return;
}

template <typename T>
void MultiSetSubtract(std::multiset<T> &ret_set, const std::multiset<T> &multiset_minuend, const std::multiset<T> &multiset_subtrahend)
{
    ret_set.clear();
    // Iterate all unique elements in minuend
    for (auto unique_elem = multiset_minuend.cbegin(); unique_elem != multiset_minuend.cend(); unique_elem = multiset_minuend.upper_bound(*unique_elem))
    {
        if (multiset_minuend.count(*unique_elem) > multiset_subtrahend.count(*unique_elem))
        {
            std::size_t elem_size = multiset_minuend.count(*unique_elem) - multiset_subtrahend.count(*unique_elem);
            AddMultiElemToSet(ret_set, elem_size, *unique_elem);
        }
    }
    return;
}


template <typename T>
void MultiSetAdd(std::multiset<T> &ret_set, const std::multiset<T> &original_multiset_a, const std::multiset<T> &original_multiset_b)
{
    ret_set.clear();
    // Iterate all unique elements in multiset a
    for (auto unique_elem = original_multiset_a.cbegin(); unique_elem != original_multiset_a.cend(); unique_elem = original_multiset_a.upper_bound(*unique_elem))
    {
        std::size_t elem_size = original_multiset_a.count(*unique_elem) + original_multiset_b.count(*unique_elem);
        AddMultiElemToSet(ret_set, elem_size, *unique_elem);
    }
    // Iterate all unique elements in multise b, ignore any element already put into ret_set
    for (auto unique_elem = original_multiset_b.cbegin(); unique_elem != original_multiset_b.cend(); unique_elem = original_multiset_b.upper_bound(*unique_elem))
    {
        if (ret_set.find(*unique_elem) != ret_set.cend())    // element already exists
            continue;
        else
        {
            std::size_t elem_size = original_multiset_b.count(*unique_elem);
            AddMultiElemToSet(ret_set, elem_size, *unique_elem);
        }
    }
    return;
}

template <typename T>
using FuzzySet = std::map<T, double>;

template <typename T>
void FuzzySetComplement(FuzzySet<T> &ret_set, const FuzzySet<T> &universal_set, const FuzzySet<T> &original_set)
{
    ret_set.clear();
    for (auto elem : universal_set)
    {
        auto target_iter = original_set.find(elem.first);
        if (target_iter == original_set.end())
        {
            ret_set[elem.first] = 1.0;
        }
        else
        {
            ret_set[elem.first] = 1.0 - (*target_iter).second;
        }
    }
    return;
}

template <typename T>
void FuzzySetUnion(FuzzySet<T> &ret_set, const FuzzySet<T> &original_set_a, const FuzzySet<T> &original_set_b)
{
    ret_set.clear();
    for (auto elem : original_set_a)
    {
        auto target_iter = original_set_b.find(elem.first);
        if (target_iter == original_set_b.end())
        {
            ret_set[elem.first] = elem.second;
        }
        else
        {
            ret_set[elem.first] = (elem.second >= (*target_iter).second ? elem.second : (*target_iter).second);
        }
    }
    for (auto elem : original_set_b)
    {
        auto target_iter = original_set_a.find(elem.first);
        if (target_iter == original_set_a.end())
        {
            ret_set[elem.first] = elem.second;
        }
    }
    return;
}

template <typename T>
void FuzzySetIntersection(FuzzySet<T> &ret_set, const FuzzySet<T> &original_set_a, const FuzzySet<T> &original_set_b)
{
    ret_set.clear();
    for (auto elem : original_set_a)
    {
        auto target_iter = original_set_b.find(elem.first);
        if (target_iter != original_set_b.end())
        {
            ret_set[elem.first] = (elem.second <= (*target_iter).second ? elem.second : (*target_iter).second);
        }
    }
    return;
}

template <typename T1, typename T2>
using CartesianProducts = std::set<std::pair<T1, T2>>;

template <typename T1, typename T2>
void GenerateCartesianProduct(CartesianProducts<T1, T2> &ret_set, const std::set<T1> &first_set, const std::set<T2> &second_set)
{
    ret_set.clear();
    for (auto elem_first : first_set)
    {
        for (auto elem_second : second_set)
        {
            ret_set.insert(std::make_pair(elem_first, elem_second));
        }
    }
    return;
}

template <typename T>
using Powerset = std::set<std::set<T>>;

template <typename T>
void GeneratePowerSets(Powerset<T> &output, const std::set<T> &original_set)
{
    output.clear();
    int power_set_size = static_cast<int>(std::pow(2, original_set.size()));
    for (int i = 0; i < power_set_size; i++)
    {
        std::set<T> power_set_elem({});
        auto iter = original_set.begin();
        for (int j = 0; j < original_set.size(); j++)
        {
            if ((0x01 << j) & i)
            {
                power_set_elem.insert(*iter);
            }
            iter++;

        }
        output.insert(power_set_elem);
    }
    return;
}

#endif
