#include<iostream>
#include<fstream>
#include "board.hpp"
#include "view.hpp"
using namespace std;

// Programme principale "executable" qui permet de tester la fonction read_FEN
int main (){
    square Plateau2D[L][C]; // declaration du Plateau2D
    string fichier="FEN1.txt";  // declaration du fichier contenant la notation FEN qu'on souhaite lire
    read_FEN(Plateau2D,fichier); // la lecture du fichier FEN1.txt  qui contient la notation FEN
    print_board(Plateau2D);  // afficher l'echiquier 


    return 0;
}

