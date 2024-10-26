#ifndef GAME_HPP
#define GAME_HPP

#include "Piece.hpp"
#include <SFML/Graphics.hpp>
#include "Constants.hpp"
class Game {
    static int player;
    Piece* board[8][8];
    Piece * selected_piece;
    public:
        Game();
        void move(int x0, int y0, int x1, int y1);
        void select_piece(sf::Vector2i mouse_pos);
        void draw_board(sf::RenderWindow &window);
        void draw_pieces(sf::RenderWindow &window);
        void print_grid();

};

#endif