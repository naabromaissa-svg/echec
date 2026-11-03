#ifndef   _board_HPP 
#define   _board_HPP 
#include "types.hpp"

void empty_1D(square Plateau1D[N]);
void empty_2D(square Plateau1D[L][C]);
square get_square_1D(square Plateau1D[N] , int l , int c);
square get_square_2D(square Plateau2D[L][C], int l , int c);
void set_square_1D(square Plateau1D[N] , int l, int c , square piece);
void set_square_2D(square Plateau1D[L][C] , int l, int c , square piece);
void start_1D(square Plateau1D[N]);
void start_2D(square Plateau1D[L][C]);
void move_piece_1D(square Plateau1D[N] , int l1 , int c1 , int l2 , int c2);
void move_piece_2D(square Plateau1D[L][C] , int l1 , int c1 , int l2 , int c2);

#endif 