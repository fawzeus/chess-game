#ifndef PIECE_HPP
#define PIECE_HPP

#include "Constants.hpp"

class Piece{
    enum TYPE type;
    int x,y;
    public:
        Piece(enum TYPE type, int x, int y);
};


#endif