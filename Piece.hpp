#ifndef PIECE_HPP
#define PIECE_HPP

#include "Constants.hpp"
#include <SFML/Graphics.hpp>
class Piece{
    enum TYPE type;
    int x,y;
    sf::Texture texture; 
    sf::Sprite sprite;
    int color;
    public:
        Piece(enum TYPE type, int x, int y, int color);
        void draw(sf::RenderWindow &window);
};


#endif