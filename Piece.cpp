#include "Piece.hpp"

Piece::Piece(enum TYPE type, int x, int y, int color)
    : type(type), x(x), y(y), color(color) {
    
    // Choose the appropriate image map based on the color (1 for dark, 0 for light)
    const std::map<TYPE, std::string>& pieceImages = (color == 1) ? pieceImagesDark : pieceImagesLight;
    std::string imagePath = pieceImages.at(type);
    // Load the texture from the image file
    if (!texture.loadFromFile("images/"+imagePath)) {
        throw std::runtime_error("Could not load texture: " + imagePath);
    }

    sprite.setTexture(texture);
    sf::FloatRect bounds = sprite.getGlobalBounds();
    sprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
    float posX = static_cast<float>(x * SQUARE_SIZE) + SQUARE_SIZE / 2.0f+50;
    float posY = static_cast<float>(y * SQUARE_SIZE) + SQUARE_SIZE / 2.0f+50;
    sprite.setPosition(posX, posY);
}

void Piece::draw(sf::RenderWindow &window){
    window.draw(sprite);
}

void Piece::set_position(int x, int y){
    this->x=x;
    this->y=y;
}

sf::Vector2i Piece::get_position(void){
    return  sf::Vector2i(x,y);
}