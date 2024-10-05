#include "Game.hpp"

void Game::draw_board(sf::RenderWindow &window){
    float pos_x=50,pos_y;
    for(int i=0;i<8;i++){
        pos_y=50;
        for(int j=0;j<8;j++){
            sf::Vector2f position(pos_x,pos_y);
            sf::RectangleShape rectangle(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
            rectangle.setPosition(position);
            rectangle.setFillColor(sf::Color::Transparent);
            // Set the outline color (e.g., black) and thickness
            rectangle.setOutlineColor(sf::Color::White);
            rectangle.setOutlineThickness(2);  // Adjust the thickness if necessary
            //highlight.setFillColor(sf::Color::Red);
            window.draw(rectangle);
            pos_y+=SQUARE_SIZE;
        }
        pos_x+=SQUARE_SIZE;
    }

}