/*
 * exercise05.cc
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Given a portion of a checkerboard, look for tiling of this
 * checkerboard with various types of polyominoes, including
 * dominoes, the two types of triominoes, and larger polyominoes.
 */

#include <cstddef>

class Polyomino
{
public:
    virtual ~Polyomino() = 0;
protected:
    Polyomino(std::size_t tiles): tile_size(tiles) { }
private:
    std::size_t tile_size;
};

class Domino : public Polyomino
{
};

class Triomino : public Polyomino
{
};

int main(void)
{
    return 0;
}



