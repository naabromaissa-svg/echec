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

    // On crée situation d'échec simple
    move_piece_2D(Plateau, 6, 4, 4, 4); // pion noir avance
    move_piece_2D(Plateau, 1, 3, 3, 3); // pion blanc avance
    move_piece_2D(Plateau, 7, 3, 3, 7); // dame noire attaque

    Mask m= empty_mask();
    print_board_color(Plateau,m);

    if(king_in_check(Plateau, true)){
        cout << "Le roi blanc est en echec !" << endl;
    }
    else{
        cout << "Le roi blanc n'est pas en echec." << endl;
    }

    return 0;
}