#ifndef   _mask_HPP 
#define   _mask_HPP 

#include "types.hpp"
#include "board.hpp"
using namespace std;



Mask empty_mask();
void clear_mask(Mask *m);
int get_mask(Mask m , int l , int c);
void set_mask(Mask *m , int l , int c , int caseMask);
bool est_blanc(square piece);
bool move_valide(square Plateau2D[L][C], int y, int x, int l, int c);
void highlight_possible_move(square Plateau2D[L][C],Mask *m, int l , int c);
void highlight_possible_move_king(square Plateau2D[L][C], Mask *m , int l , int c );
void highlight_possible_move_rook(square Plateau2D[L][C], Mask *m , int l , int c );
void highlight_possible_move_bishop(square Plateau2D[L][C], Mask *m , int l , int c );
void highlight_possible_move_queen(square Plateau2D[L][C], Mask *m , int l , int c );
void highlight_possible_move_knight(square Plateau2D[L][C], Mask *m , int l , int c );
void highlight_possible_move_pawn(square Plateau2D[L][C], Mask *m , int l , int c );
void highlight_moveble_pieces(square Plateau2D[L][C],Mask *m, bool blanc);
void highlight_attacked_pieces(square Plateau2D[L][C],Mask *m, bool blanc);
void highlight_take_pieces(square Plateau2D[L][C],Mask *m, bool blanc);
void mask_choices_menu();
void mask_choices(square Plateau2D[L][C],Mask *m);

#endif