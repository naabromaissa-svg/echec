#ifndef   _game_HPP 
#define   _game_HPP 

#include "types.hpp"
#include "board.hpp"
#include "mask.hpp" 
using namespace std;

bool king_in_check(square Plateau[L][C], bool roi_blanc);
bool choose_mouvement_king_in_check_computer(square Plateau[L][C], bool blanc);
bool test_run(square Plateau[L][C], int l1, int c1 , int l2 , int c2 );
void choose_mouvement_human(square Plateau[L][C], Mask *m, bool blanc);

void one_run_human(square Plateau[L][C], Mask *m, bool blanc);
void choose_mouvement_computer(square Plateau[L][C], Mask *m, int l, int c);
void one_run_computer(square Plateau[L][C], Mask *m, bool blanc);

void one_run(square Plateau[L][C], Mask *m, bool human, bool blanc, int *nb_positions);
void play_game(square Plateau[L][C]);




#endif