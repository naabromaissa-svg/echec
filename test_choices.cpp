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

    move_piece_2D(  Plateau, 0 , 3 , 5 ,7 );


    Mask m=empty_mask();

    mask_choices_menu();

    mask_choices(Plateau, &m);

    return 0;
}