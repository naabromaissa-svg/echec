#include<iostream>
#include"types.hpp"
#include "board.hpp"
#include "view.hpp"
#include "mask.hpp"


using namespace std;

int main(){
    square Plateau[L][C];
    start_2D(Plateau);
    move_piece_2D(  Plateau, 0 , 1 , 5 ,4 );

    Mask m=empty_mask();
    highlight_possible_move_knight(Plateau, &m , 5, 4 );
    print_board_color( Plateau , m);






    return 0;
}