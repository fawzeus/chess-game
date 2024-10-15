#include "Game.hpp"

void Game::draw_board(sf::RenderWindow &window){
    float pos_x=50,pos_y;
    for(int i=0;i<8;i++){
        pos_y=50;
        for(int j=0;j<8;j++){
            sf::Vector2f position(pos_x,pos_y);
            sf::RectangleShape rectangle(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
            rectangle.setPosition(position);
            if((i+j)%2==0)
                rectangle.setFillColor( sf::Color(220,220,220));
            else 
                rectangle.setFillColor(sf::Color(50,205,50));
            // Set the outline color (e.g., black) and thickness
            rectangle.setOutlineColor(sf::Color::Black);
            rectangle.setOutlineThickness(2);  // Adjust the thickness if necessary
            //highlight.setFillColor(sf::Color::Red);
            window.draw(rectangle);
            pos_y+=SQUARE_SIZE;
        }
        pos_x+=SQUARE_SIZE;
    }

}

Game::Game(){
    //init pawns
    selected_piece = NULL;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            board[i][j]=NULL;
        }
    }
    for(int i=0;i<8;i++){
        board[i][1]= new Piece(PAWN,i,1,1);
        board[i][6] = new Piece(PAWN,i,6,0);
    }
    //init rooks
    board[0][7] = new Piece(ROOK,0,7,0);
    board[7][7] = new Piece(ROOK,7,7,0);
    board[0][0] = new Piece(ROOK,0,0,1);
    board[7][0] = new Piece(ROOK,7,0,1);
    //init knights
    board[1][7] = new Piece(KNIGHT,1,7,0);
    board[6][7] = new Piece(KNIGHT,6,7,0);
    board[1][0] = new Piece(KNIGHT,1,0,1);
    board[6][0] = new Piece(KNIGHT,6,0,1);
    //init bishops
    board[2][7] = new Piece(BISHOP,2,7,0);
    board[5][7] = new Piece(BISHOP,5,7,0);
    board[2][0] = new Piece(BISHOP,2,0,1);
    board[5][0] = new Piece(BISHOP,5,0,1);
    //init queens
    board[3][7] = new Piece(QUEEN,3,7,0);
    board[3][0] = new Piece(QUEEN,3,0,1);
    //init kings
    board[4][7] = new Piece(KING,4,7,0);
    board[4][0] = new Piece(KING,4,0,1);
    

}

void Game::draw_pieces(sf::RenderWindow &window){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]!=NULL){
                board[i][j]->draw(window);
            }
        }
    }
}

void Game::select_piece(sf::Vector2i mouse_pos){
    puts("called!");
    int x = mouse_pos.x-50,y=mouse_pos.y-50;
    if(x<0 or y<0) return;
    x = x/SQUARE_SIZE;
    y = y/SQUARE_SIZE;
    if(!(x>=0 and y>=0 and x<=7 and y<=7))return;
    //printf("(%d,%d)\n",x,y);
    if(selected_piece!=NULL){
        puts("entered!");
        if (board[y][x] == NULL){
            puts("moved !!");
            selected_piece->set_position(x,y);
            sf::Vector2i old_pos = selected_piece->get_position();
            board[old_pos.y][old_pos.x] = NULL;
            board[y][x] = selected_piece;
            selected_piece = NULL;
        }
    }
    else if(board[x][y]!=NULL){
        puts("selected");
        printf("(%d,%d)\n",x,y);
        selected_piece = board[y][x];
    }
}