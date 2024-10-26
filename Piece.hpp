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
        void set_position(int x,int y);
        sf::Vector2i get_position(void);
        enum TYPE get_type(void);
};


#endif