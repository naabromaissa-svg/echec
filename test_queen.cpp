#include<iostream>
#include"types.hpp"
#include "board.hpp"
#include "view.hpp"
#include "mask.hpp"


using namespace std;

int main(){
    square Plateau[L][C];
    start_2D(Plateau);
    move_piece_2D(  Plateau, 0 , 3 , 3 ,3 );

    Mask m=empty_mask();
    highlight_possible_move_queen(Plateau, &m , 3, 3 );
    print_board_color( Plateau , m);






    return 0;
}