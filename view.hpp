#ifndef   _view_HPP 
#define   _view_HPP 
#include <string>
#include "board.hpp"
#include "types.hpp"
using namespace std;
 
void print_square(square Plateau2D[L][C], int l1, int c1);
void print_board(square Plateau2D[L][C]);
void write_FEN(square Plateau2D[L][C] , string fichier, ios_base::openmode mode);
void read_FEN(square Plateau[L][C] , string fichier);

void set_background(int color);
void set_foreground(int color);
void print_square_color(square Plateau2D[L][C], int l1, int c1);
void print_board_color(square Plateau2D[L][C], Mask m);

#endif
