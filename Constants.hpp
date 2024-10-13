#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

const int WIDTH = 1000;
const int HEIGHT = 800;
const int SQUARE_SIZE = 60;

#include <map>
enum TYPE {
    PAWN = 1,
    BISHOP = 3,
    KNIGHT = 3,
    ROOK = 5,
    QUEEN = 9,
    KING = 0
};



const std::map<TYPE, std::string> pieceImagesDark = {
    {PAWN, "Chess_pdt60.png"},
    {BISHOP, "Chess_bdt60.png"},
    {KNIGHT, "Chess_ndt60.png"},
    {ROOK, "Chess_rdt60.png"},
    {QUEEN, "Chess_qdt60.png"},
    {KING, "Chess_kdt60.png"}
};

const std::map<TYPE, std::string> pieceImagesLight = {
    {PAWN, "Chess_plt60.png"},
    {BISHOP, "Chess_blt60.png"},
    {KNIGHT, "Chess_nlt60.png"},
    {ROOK, "Chess_rlt60.png"},
    {QUEEN, "Chess_qlt60.png"},
    {KING, "Chess_klt60.png"}
};


#endif