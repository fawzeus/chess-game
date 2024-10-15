#include "Game.hpp"
#include <SFML/Graphics.hpp>


int main (){
    Game game;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Chess Game");
    while(window.isOpen()){
        sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                else if(event.type == sf::Event::MouseButtonPressed){
                    sf::Vector2i mouse_pos =  sf::Mouse::getPosition(window);
                    game.select_piece(mouse_pos);
                    //printf("(%d,%d)\n",mouse_pos.x,mouse_pos.y);
                }
            }
            window.clear( sf::Color(87,65,47));
            game.draw_board(window);
            game.draw_pieces(window);
            window.display();
            
    }
}