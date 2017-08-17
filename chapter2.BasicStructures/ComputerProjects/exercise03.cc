/*
 * exercise03.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given fuzzy sets A and B, find complement of A,
 * union of A and B, and intersection of A and B
 */

#include "SetHelper.h"
#include <string>
#include <cassert>
#include <iostream>
#include <limits>
#include <cmath>

int main(void)
{
    FuzzySet<std::string> string_fuzzy_set_f;
    string_fuzzy_set_f["Alice"] = 0.6;
    string_fuzzy_set_f["Brian"] = 0.9;
    string_fuzzy_set_f["Fred"] = 0.4;
    string_fuzzy_set_f["Oscar"] = 0.1;
    string_fuzzy_set_f["Rita"] = 0.5;
    FuzzySet<std::string> string_fuzzy_set_r;
    string_fuzzy_set_r["Alice"] = 0.4;
    string_fuzzy_set_r["Brian"] = 0.8;
    string_fuzzy_set_r["Fred"] = 0.2;
    string_fuzzy_set_r["Oscar"] = 0.9;
    string_fuzzy_set_r["Rita"] = 0.7;
    FuzzySet<std::string> string_fuzzy_set_universal;
    string_fuzzy_set_universal["Alice"] = 1.0;
    string_fuzzy_set_universal["Brian"] = 1.0;
    string_fuzzy_set_universal["Fred"] = 1.0;
    string_fuzzy_set_universal["Oscar"] = 1.0;
    string_fuzzy_set_universal["Rita"] = 1.0;
    string_fuzzy_set_universal["Rui"] = 1.0;
    {
        FuzzySet<std::string> output;
        FuzzySetComplement(output, string_fuzzy_set_universal, string_fuzzy_set_f);
        assert(std::abs(output["Alice"] - 0.4) <= std::numeric_limits<double>::epsilon());
        assert(std::abs(output["Brian"] - 0.1) <= std::numeric_limits<double>::epsilon());
        assert(std::abs(output["Fred"] - 0.6) <= std::numeric_limits<double>::epsilon());
        assert(std::abs(output["Oscar"] - 0.9) <= std::numeric_limits<double>::epsilon());
        assert(std::abs(output["Rita"] - 0.5) <= std::numeric_limits<double>::epsilon());
        assert(std::abs(output["Rui"] - 1.0) <= std::numeric_limits<double>::epsilon());
    }
    {
        FuzzySet<std::string> output;
        FuzzySetUnion(output, string_fuzzy_set_f, string_fuzzy_set_r);
        assert(std::abs(output["Alice"] - 0.6) <= std::numeric_limits<double>::epsilon());
        assert(std::abs(output["Brian"] - 0.9) <= std::numeric_limits<double>::epsilon());
        assert(std::abs(output["Fred"] - 0.4) <= std::numeric_limits<double>::epsilon());
        assert(std::abs(output["Oscar"] - 0.9) <= std::numeric_limits<double>::epsilon());
        assert(std::abs(output["Rita"] - 0.7) <= std::numeric_limits<double>::epsilon());
    }
    {
        FuzzySet<std::string> output;
        FuzzySetIntersection(output, string_fuzzy_set_f, string_fuzzy_set_r);
        assert(std::abs(output["Alice"] - 0.4) <= std::numeric_limits<double>::epsilon());
        assert(std::abs(output["Brian"] - 0.8) <= std::numeric_limits<double>::epsilon());
        assert(std::abs(output["Fred"] - 0.2) <= std::numeric_limits<double>::epsilon());
        assert(std::abs(output["Oscar"] - 0.1) <= std::numeric_limits<double>::epsilon());
        assert(std::abs(output["Rita"] - 0.5) <= std::numeric_limits<double>::epsilon());
    }

    return 0;
}

