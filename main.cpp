#include<iostream>
#include<fstream>
#include "board.hpp"
#include "view.hpp"
#include "mask.hpp"
#include "game.hpp"
#include "types.hpp"

using namespace std;


int main(){
    square Plateau[L][C];
    start_2D(Plateau);

    play_game(Plateau);

    return 0;
}