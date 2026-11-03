#include<iostream>
#include "types.hpp"
using namespace std;

// Initialise toutes les cases du plateau 1D a vide
void empty_1D(square Plateau1D[N]){
    for(int i=0; i<N; i++)
        Plateau1D[i] = vide;
}

// Initialise toutes les cases du plateau 2D a vide
void empty_2D(square Plateau2D[L][C]){
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++)
            Plateau2D[i][j] = vide;
}

// Retourne le contenu de la case (l,c) du plateau 1D, vide si case invalide
square get_square_1D(square Plateau1D[N], int l, int c){
    if (l < 0 || l >= L || c < 0 || c >= C){
        cout << "Erreur acces (" << l << "," << c << ")" << endl;
        return vide;
    }
    return Plateau1D[l*C+c];
}

// Retourne le contenu de la case (l,c) du plateau 2D, vide si case invalide
square get_square_2D(square Plateau2D[L][C], int l, int c){
    if (l < 0 || l >= L || c < 0 || c >= C){
        cout << "Erreur acces (" << l << "," << c << ")" << endl;
        return vide;
    }
    return Plateau2D[l][c];
}

// Modifie le contenu de la case (l,c) du plateau 1D avec la piece donnee
void set_square_1D(square Plateau1D[N], int l, int c, square piece){
    if (l < 0 || l >= L || c < 0 || c >= C){
        cout << "Erreur ecriture (" << l << "," << c << ")" << endl;
        return;
    }
    Plateau1D[l*C+c] = piece;
}

// Modifie le contenu de la case (l,c) du plateau 2D avec la piece donnee
void set_square_2D(square Plateau2D[L][C], int l, int c, square piece){
    if (l < 0 || l >= L || c < 0 || c >= C){
        cout << "Erreur ecriture (" << l << "," << c << ")" << endl;
        return;
    }
    Plateau2D[l][c] = piece;
}

// Initialise le plateau 1D avec la position de depart des pieces
void start_1D(square Plateau1D[N]){
    empty_1D(Plateau1D);
    for(int c=0; c<8; c++){
        Plateau1D[1*C+c] = Bpion;
        Plateau1D[6*C+c] = Npion;
    }
    Plateau1D[0]=Btour;   
    Plateau1D[7]=Btour;
    Plateau1D[7*C+0]=Ntour; 
    Plateau1D[7*C+7]=Ntour;
    Plateau1D[1]=Bcavalier; 
    Plateau1D[6]=Bcavalier;
    Plateau1D[7*C+1]=Ncavalier; 
    Plateau1D[7*C+6]=Ncavalier;
    Plateau1D[2]=Bfou;    
    Plateau1D[5]=Bfou;
    Plateau1D[7*C+2]=Nfou;  
    Plateau1D[7*C+5]=Nfou;
    Plateau1D[3]=Bdame;   
    Plateau1D[7*C+3]=Ndame;
    Plateau1D[4]=Broi;    
    Plateau1D[7*C+4]=Nroi;
}

// Initialise le plateau 2D avec la position de depart des pieces
void start_2D(square Plateau2D[L][C]){
    empty_2D(Plateau2D);
    for(int c=0; c<8; c++){
        Plateau2D[1][c] = Bpion;
        Plateau2D[6][c] = Npion;
    }
    Plateau2D[0][0]=Btour;    
    Plateau2D[0][7]=Btour;
    Plateau2D[7][0]=Ntour;   
    Plateau2D[7][7]=Ntour;
    Plateau2D[0][1]=Bcavalier; 
    Plateau2D[0][6]=Bcavalier;
    Plateau2D[7][1]=Ncavalier; 
    Plateau2D[7][6]=Ncavalier;
    Plateau2D[0][2]=Bfou;     
    Plateau2D[0][5]=Bfou;
    Plateau2D[7][2]=Nfou;     
    Plateau2D[7][5]=Nfou;
    Plateau2D[0][3]=Bdame;    
    Plateau2D[7][3]=Ndame;
    Plateau2D[0][4]=Broi;     
    Plateau2D[7][4]=Nroi;
}

// Deplace la piece de la case (l1,c1) vers la case (l2,c2) dans le plateau 1D
void move_piece_1D(square Plateau1D[N], int l1, int c1, int l2, int c2){
    if (l1<0 || l1>=L || c1<0 || c1>=C || l2<0 || l2>=L || c2<0 || c2>=C){
        cout << "Erreur mouvement !" << endl;
        return;
    }
    Plateau1D[l2*C+c2] = Plateau1D[l1*C+c1];
    Plateau1D[l1*C+c1] = vide;
}

// Deplace la piece de la case (l1,c1) vers la case (l2,c2) dans le plateau 2D
void move_piece_2D(square Plateau2D[L][C], int l1, int c1, int l2, int c2){
    if (l1<0 || l1>=L || c1<0 || c1>=C || l2<0 || l2>=L || c2<0 || c2>=C){
        cout << "Erreur mouvement !" << endl;
        return;
    }
    set_square_2D(Plateau2D, l2, c2, get_square_2D(Plateau2D, l1, c1));
    set_square_2D(Plateau2D, l1, c1, vide);
}