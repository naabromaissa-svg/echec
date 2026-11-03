#include<iostream>
#include"types.hpp"
#include "board.hpp"
#include "view.hpp"
#include "mask.hpp"

using namespace std;

int main(){
    square Plateau[L][C];
    start_2D(Plateau);
    move_piece_2D(  Plateau, 0 , 4 , 3 ,7 );

    Mask m=empty_mask();
    highlight_possible_move_king(Plateau, &m , 3, 7 );
    print_board_color( Plateau , m);






    return 0;
}