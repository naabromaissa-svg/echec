#include<iostream>
#include <random>
#include"types.hpp"
#include"board.hpp"
#include"view.hpp"
#include"mask.hpp"
#include"game.hpp"
#include"historique.hpp"

using namespace std;

int main (){
    square Plateau2D[L][C];  // On declare le plateau2D 
    string fichier="FEN2.txt";   //On declare le fichier dans lequel on souahite voir la notation FEN
    start_2D(Plateau2D);  
    Mask m=empty_mask();
    int nb_positions=0;
    one_run( Plateau2D, &m, false,  true , &nb_positions);


    return 0;

}