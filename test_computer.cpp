#include<iostream>
#include "types.hpp"
#include "board.hpp"
#include "view.hpp"
#include "mask.hpp"
#include "game.hpp"


using namespace std;

// la fonction choose_mouvement_computer est testee implicitement ici 
//si one_run_computer fonctionne correctement, cela signifie que la selection des pieces, la generation des mouvements, la selection aleatoire d'un coup et le deplacemet d'une pieces sont tous correctes
//Donc la validation de one_run_computer valide egalement indirectement choose_movement_computer c'est pour cela on a fait juste un seul test directement pour one_run_computer
int main(){
    square Plateau[L][C];
    start_2D(Plateau);
    move_piece_2D(  Plateau, 0 , 4 , 3 ,7 );

    Mask m=empty_mask();
    
    one_run_computer(Plateau, &m, true);
    
    print_board_color(Plateau , m);




    return 0;
}