#include<iostream>
#include"types.hpp"
#include "board.hpp"
#include "view.hpp"
#include "mask.hpp"


using namespace std;

int main(){
    square Plateau[L][C];
    start_2D(Plateau);
    move_piece_2D(  Plateau, 6 , 6 , 2 ,1 );

    Mask m=empty_mask();
    highlight_possible_move_pawn(Plateau, &m , 1, 1 );

    print_board_color( Plateau , m);




    return 0;
}