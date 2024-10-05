#ifndef GAME_HPP
#define GAME_HPP

#include "Piece.hpp"
#include <SFML/Graphics.hpp>
#include "Constants.hpp"
class Game {
    static int player;
    enum TYPE board[8][8];
    public:
        Game(){}
        void init();
        void move(int x0, int y0, int x1, int y1);
        void draw_board(sf::RenderWindow &window);

};

#endif