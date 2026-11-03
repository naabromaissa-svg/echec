#include<iostream>
#include<string>
#include<fstream>
#include "types.hpp"
#include "board.hpp"
#include"mask.hpp"
using namespace std;



//Fonction qui permet d'afficher une case du plateau2D sous forme de caractere correspendant a chaque piece de l'echiquier

void print_square(square Plateau2D[L][C], int l1, int c1){
    int x = Plateau2D[l1][c1];
    string s;
    if(x == Ntour)s = "♜";   // On associe chaque piece avec son caractere en notation FEN
    else if(x == Ncavalier)s = "♞";
    else if(x == Nfou)s = "♝";
    else if(x == Ndame)s = "♛";
    else if(x == Nroi)s = "♚";
    else if(x == Npion)s = "♟";
    else if(x == Btour)s = "♖";
    else if(x == Bcavalier)s = "♘";
    else if(x == Bfou)s = "♗";
    else if(x == Bdame)s = "♕";
    else if(x == Broi)s = "♔";
    else if(x == Bpion)s = "♙";
    else s = "  "; // ← 2 espaces pour case vide
    
    if(x == vide) cout << s;
    else cout << s << " "; // ← espace après le symbole pour équilibrer
}

// Fonction qui permet d'affichier le plateau2D  c-a-d l'echiquier
void print_board(square Plateau2D[L][C]){
    cout << "  a b c d e f g h  " << endl;   // afficher le haut de l'echiquier les colonnes de a jusqu'a h
    for(int j = L-1; j>-1 ; j--){
        cout << (j+1) << " ";      // afficher la numerotation des lignes 
        for(int i = 0; i < C; i++){
            print_square(Plateau2D,j,i);  // afficher les cases 
        }   
        cout << " " << (j+1) << endl;    //afficher la numerotation des lignes
    }
    cout << "  a b c d e f g h  " << endl;  // afficher le bas de l'echiquier les colonnes de a jusqu'a h
}



// Fonction qui permet d'ecrire l'etat d'un plateau2D en notation FEN dans un fichier precis
void write_FEN(square Plateau2D[L][C], string fichier , ios_base::openmode mode){
  
    ofstream fic(fichier , mode);
    string ch_FEN="";  // on definie la notation FEN en une chaine FEN 
    int tmp;
    int n = 0;   // un compteur du nombre des cases vides
    for(int j = L-1; j>-1 ; j--){

        for(int i = 0; i < C; i++){
            tmp = get_square_2D(Plateau2D , j , i);   // on recupere la case dans une variable temporaire
            if (tmp == vide) n+=1;   // si la case est un vide le nombre de vide augmente
            else {
                if(n != 0){
                    ch_FEN += to_string(n);    // ajouter le nombre de cases vides a la chaine FEN
                    n = 0;
                }

                if(tmp == Ntour)ch_FEN += "r";    // on ajoute les autre spieces de l'echiquier
                else if(tmp == Ncavalier)ch_FEN += "n";
                else if(tmp == Nfou)ch_FEN += "b";
                else if(tmp == Ndame)ch_FEN += "q";
                else if(tmp == Nroi)ch_FEN += "k";
                else if(tmp == Npion)ch_FEN += "p";
                else if(tmp == Btour)ch_FEN += "R";
                else if(tmp == Bcavalier)ch_FEN += "N";
                else if(tmp == Bfou)ch_FEN += "B";
                else if(tmp == Bdame)ch_FEN += "Q";
                else if(tmp == Broi)ch_FEN += "K";
                else if(tmp == Bpion)ch_FEN += "P";
                else if(tmp == vide)ch_FEN += "-";
            }
        
        }
        if(n != 0){
            ch_FEN += to_string(n);   
            n = 0;
        }
        if( j != 0 )ch_FEN += "/";  // un / separateur selon la notation FEN
    }
    cout << ch_FEN<<endl;    // on affiche la notation FEN -cette ligne n'est pas obligatoire -

    if (fic) {
        fic << ch_FEN<< endl;   // ecriture dans le fichier
    }
    else{
        cout << " ERREUR : impossible d'ouvrir le fichier en sortie " << endl;
    }

    fic.close();

}


// Fonction qui permet de lire puis afficher un plateau2D a partir d'un fichier contenant la notation FEN correspendante
void read_FEN(square Plateau2D[L][C], string fichier){
    ifstream fic(fichier);
    string ch_FEN;
    if(fic){
        fic>> ch_FEN;   // lecture de la chaine FEN

        int l=7;
        int c=0;

        for(int i=0 ; i<(int)ch_FEN.size() ; i++){
            char piece=ch_FEN[i];

            if(piece=='/'){    // lorsque on arrive a un / la ligne deminue c-a-d on passe a la ligne suivante
                l--;
                c=0;
            }

            else {
                if(piece>='1' && piece<='8'){
                    int n= piece - '0';    // on convertie un caractere chiffre en un entier qui est le nombre de case vide
                    for(int j=0 ; j<n ; j++){
                        Plateau2D[l][c]=vide;
                        c++;
                    }
                }
                else{
                    if(piece =='r' ) Plateau2D[l][c]=Ntour;
                    else if(piece == 'n')Plateau2D[l][c]=Ncavalier;
                    else if(piece  == 'b')Plateau2D[l][c]=Nfou;
                    else if(piece  == 'q')Plateau2D[l][c]=Ndame;
                    else if(piece =='k')Plateau2D[l][c]=Nroi;
                    else if(piece =='p')Plateau2D[l][c]=Npion;
                    else if(piece == 'R')Plateau2D[l][c]=Btour;
                    else if(piece == 'N')Plateau2D[l][c]=Bcavalier;
                    else if(piece == 'B')Plateau2D[l][c]=Bfou;
                    else if(piece == 'Q')Plateau2D[l][c]=Bdame;
                    else if(piece == 'K')Plateau2D[l][c]=Broi;
                    else if(piece  == 'P')Plateau2D[l][c]=Bpion;

                    c++;   // on passe a la case suivante
                }
            }
        }
    }
     
    else{
        cout << "ERREUR : fichier introuvable" << endl;
    }
    fic.close();
    


}



// Applique la couleur de fond d'une case selon sa position (cases claires/sombres)
void set_background(int color){
    cout << "\x1b[48;5;" << color << "m";
}


// Applique la couleur du texte (piece) d'une case
void set_foreground(int color){
    cout << "\x1b[38;5;" << color << "m";
}


// Affiche une case avec couleurs classiques du plateau ( fond clair/sombre et pieces blanches/noires)
void print_square_color(square Plateau2D[L][C], int l1, int c1){
    int x = Plateau2D[l1][c1];

    if((l1+c1) % 2 == 0) set_background(130);
    else set_background(178);

    if (x==Btour || x==Bcavalier || x==Bfou || x==Bdame || x==Broi || x==Bpion) set_foreground(255);  
    else if(x==Ntour || x==Ncavalier || x==Nfou || x==Ndame || x==Nroi || x==Npion) set_foreground(0);
    else set_foreground((l1+c1)%2==0 ? 178 : 130); // case vide, même couleur que fond
    
    string s;
    if(x == Ntour)s = "♜";   
    else if(x == Ncavalier)s = "♞";
    else if(x == Nfou)s = "♝";
    else if(x == Ndame)s = "♛";
    else if(x == Nroi)s = "♚";
    else if(x == Npion)s = "♟";
    else if(x == Btour)s = "♖";
    else if(x == Bcavalier)s = "♘";
    else if(x == Bfou)s = "♗";
    else if(x == Bdame)s = "♕";
    else if(x == Broi)s = "♔";
    else if(x == Bpion)s = "♙";
    else s = "  "; // ← 2 espaces pour case vide
    
    if(x == vide) cout << s;
    else cout << s << " "; // ← espace après le symbole pour équilibrer
    
    cout << "\x1b[0m";
}

// Affiche le plateau avec les couleurs classiques " figure 2"
void print_board_color(square Plateau2D[L][C]){
    cout << "  a b c d e f g h" << endl; // ← espacement doublé
    for(int j = L-1; j > -1; j--){
        cout << (j+1) << " ";
        for(int i = 0; i < C; i++){
            print_square_color(Plateau2D, j, i);
        }
        cout << " " << (j+1) << endl;
    }
    cout << "  a b c d e f g h" << endl; // ← espacement doublé
}


// Fonctions de la seance 3   : Les memes fonctions precedentes mais ici on ajoute  le mask en parametre pour colorer les cases selon les valeurs du contenu du masque


void print_square_color(square Plateau2D[L][C], int l1, int c1 , Mask m){
    int x = Plateau2D[l1][c1];
    int valeur=get_mask(m , l1 ,c1);


    if(valeur==0){
        if((l1+c1) % 2 == 0) set_background(130);
        else set_background(178);
    }  


    else if(valeur==1)  set_background(196);
    else if(valeur==2)  set_background(34);
    else if(valeur==3)  set_background(208);
    else if(valeur==4)  set_background(21);
    else if(valeur==5)  set_background(93);
    else if(valeur==6)  set_background(68);
    else if(valeur==7)  set_background(252);


    if (x==Btour || x==Bcavalier || x==Bfou || x==Bdame || x==Broi || x==Bpion) set_foreground(15);  
    else if(x==Ntour || x==Ncavalier || x==Nfou || x==Ndame || x==Nroi || x==Npion) set_foreground(0);
    else set_foreground(178); // case vide, même couleur que fond
    
    string s;
    if(x == Ntour)s = "♜";   
    else if(x == Ncavalier)s = "♞";
    else if(x == Nfou)s = "♝";
    else if(x == Ndame)s = "♛";
    else if(x == Nroi)s = "♚";
    else if(x == Npion)s = "♟";
    else if(x == Btour)s = "♖";
    else if(x == Bcavalier)s = "♘";
    else if(x == Bfou)s = "♗";
    else if(x == Bdame)s = "♕";
    else if(x == Broi)s = "♔";
    else if(x == Bpion)s = "♙";
    else s = "  "; // ← 2 espaces pour case vide
    
    if(x == vide) cout << s;
    else cout << s << " "; // ← espace après le symbole pour équilibrer
    
    cout << "\x1b[0m";
}

void print_board_color(square Plateau2D[L][C] , Mask m){
    cout << "  a b c d e f g h" << endl; // ← espacement doublé
    for(int j = L-1; j > -1; j--){
        cout << (j+1) << " ";
        for(int i = 0; i < C; i++){
            print_square_color(Plateau2D, j, i, m);
        }
        cout << " " << (j+1) << endl;
    }
    cout << "  a b c d e f g h" << endl; // ← espacement doublé
}


