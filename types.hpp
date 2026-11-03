#ifndef   _types_HPP 
#define   _types_HPP 

#include <string>


const int N=64 , L=8 ,C=8;


enum square{
    Ntour,
    Ncavalier, 
    Nfou, 
    Ndame, 
    Nroi, 
    Npion, 
    Btour, 
    Bcavalier, 
    Bfou, 
    Bdame, 
    Broi, 
    Bpion,
    vide,
};

struct Mask{
    int mask[L][C];

} ;

struct game{
    square Plateau2D[L][C];
    Mask m;
    std::string historique[100];
    int nb_positions;
};



 #endif