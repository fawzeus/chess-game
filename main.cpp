#include "Game.hpp"
#include <SFML/Graphics.hpp>


int main (){
    Game game;
    Piece queen(KING,0,0,0);

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Chess Game");
    while(window.isOpen()){
        sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            window.clear( sf::Color(87,65,47));
            game.draw_board(window);
            queen.draw(window);
            window.display();
            
    }
}