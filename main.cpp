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
            }
            window.clear();
            game.draw_board(window);
            window.display();
            
    }
}