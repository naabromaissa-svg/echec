


#ifndef   _historique_HPP 
#define   _historique_HPP 
#include <string>
#include "types.hpp"
#include "board.hpp"
#include "mask.hpp" 
using namespace std;



void MAJ_historique(square Plateau[L][C], string fichier, int *nb_positions);
void play_historique(string historique[], int nb_positions);
void backtrack_historique(square Plateau[L][C], string fichier, int *nb_positions);


#endif
