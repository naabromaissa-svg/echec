#include<iostream>
#include"types.hpp"
#include "board.hpp"
#include "view.hpp"
#include "mask.hpp"


using namespace std;

int main(){

    square Plateau2D[L][C];  // declaration d'un plateau
    start_2D(Plateau2D);   // Initialisation du plateau
    Mask m=empty_mask();  // creation d'un mask
    

    for(int i=0 ; i<L ; i++){
        for(int j=0 ; j<C ; j++){
            set_mask(&m , i , j , j);   // selon la figure4  la valeur de la case du mask est egale a l'indice de la colonne de la case , c'est a dire j
        }
    }

    print_board_color(Plateau2D , m);


    return 0;
}
