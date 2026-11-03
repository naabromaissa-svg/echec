#include<iostream>
#include<fstream>
#include "board.hpp"
#include "view.hpp"
using namespace std;

// Programme principale "executable" qui permet de tester la fonction write_FEN

int main (){
    square Plateau2D[L][C];  // On declare le plateau2D 
    string fichier="FEN2.txt";   //On declare le fichier dans lequel on souahite voir la notation FEN
    start_2D(Plateau2D);   // On initialise le plateau a son etat de depart -Echiquier au debut du jeu-
    write_FEN(Plateau2D , fichier);  // On appelle la fonction write_FEN qui permet d'ecrire l'etat du plateau dans le fichier FEN2.txt


    return 0;

}