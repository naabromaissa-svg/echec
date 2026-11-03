#include<iostream>
#include "types.hpp"
#include "board.hpp"
#include "view.hpp"
#include "mask.hpp"
#include "game.hpp"


using namespace std;

// la fonction choose_mouvement_human est testee implicitement ici 
//si one_run_human fonctionne correctement, cela signifie que la saisie de l'utilisateur, la validation des mouvements et leurs executions sont tous correctes.
//Donc la validation de one_run_human valide egalement indirectement choose_movement_human c'est pour cela on a fait juste un seul test directement pour one_run_human 
int main(){
    square Plateau[L][C];
    start_2D(Plateau);



    Mask m=empty_mask();

    one_run_human(Plateau, &m, true);

    


    return 0;
}
