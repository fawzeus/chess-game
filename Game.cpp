#include "Game.hpp"

void Game::draw_board(sf::RenderWindow &window){
    float pos_x=50,pos_y;
    for(int i=0;i<8;i++){
        pos_y=50;
        for(int j=0;j<8;j++){
            sf::Vector2f position(pos_x,pos_y);
            sf::RectangleShape rectangle(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
            rectangle.setPosition(position);
            if(selected_piece!=NULL and selected_piece->get_position().x==i and selected_piece->get_position().y==j)
                rectangle.setFillColor( sf::Color(255,0,0));
            else if((i+j)%2==0)
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
    print_grid();

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
    print_grid();
    //puts("called!");
    int x = mouse_pos.x-50,y=mouse_pos.y-50;
    if(x<0 or y<0) return;
    x = x/SQUARE_SIZE;
    y = y/SQUARE_SIZE;
    //printf("x = %d , y = %d",x,y);
    if(!(x>=0 and y>=0 and x<=7 and y<=7))return;
    printf("clicked (%d,%d)\n",x,y);
    //printf("(%d,%d)\n",x,y);
    if(selected_piece==NULL and board[x][y]==NULL) {
        puts("returned");
        return;
    }
    else if (selected_piece != NULL) {
        // Attempting to move the selected piece to an empty position
        if (board[x][y] == NULL) {
            // Store old position
            sf::Vector2i old_pos = selected_piece->get_position();

            // Move piece to new position and update board array
            selected_piece->set_position(x, y);
            board[old_pos.y][old_pos.x] = NULL;
            board[x][y] = selected_piece;

            // Deselect piece
            selected_piece = NULL;

            puts("Piece moved!");
            printf("New position: (%d,%d)\n", x, y);
        }
    } else if (board[x][y] != NULL) {
        // Select the piece at the clicked position
        selected_piece = board[x][y];
        puts("Piece selected");
        printf("Position: (%d,%d)\n", x, y);
    }
}

void Game::print_grid(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[j][i]!=NULL){
                printf("in position (%d,%d) there is a %d\n",i,j,board[j][i]->get_type());
            }
            else{
                printf("pos (%d,%d)\n",i,j);
            }
        }
        puts("");
    }
}