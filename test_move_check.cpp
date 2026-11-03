#include<iostream>
#include "types.hpp"
#include "board.hpp"
#include "view.hpp"
#include "mask.hpp"
#include "game.hpp"

using namespace std;

int main(){

    square Plateau[L][C];
    start_2D(Plateau);

    // Situation d'échec
    move_piece_2D(Plateau, 6, 4, 4, 4);
    move_piece_2D(Plateau, 1, 3, 3, 3);
    move_piece_2D(Plateau, 7, 3, 3, 7);

    Mask m = empty_mask();

    print_board_color(Plateau,m);

    cout << "Test mouvement ordinateur en situation d'echec..." << endl;

    choose_mouvement_king_in_check_computer(Plateau, true);

    print_board_color(Plateau,m);

    return 0;
}