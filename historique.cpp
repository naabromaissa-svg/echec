
#include<iostream>
#include<fstream>
#include"types.hpp"
#include"board.hpp"
#include"view.hpp"
#include"mask.hpp"

using namespace std;



// enregistre l'historique
void MAJ_historique(square Plateau[L][C], string fichier, int *nb_positions){

    write_FEN(Plateau, fichier, ios_base::app);

    (*nb_positions)++;
}

// afficher le plateau de puis le début du jeu
void play_historique(string historique[], int nb_positions){

    square Plateau[L][C];

    for(int i = 0; i < nb_positions; i++){

        read_FEN(Plateau, historique[i]);
        print_board(Plateau);
        cout << endl;
    }
}

// reinitialiser le plateau à l'étape désigner
void backtrack_historique(square Plateau[L][C], string fichier, int *nb_positions){

    if(*nb_positions <= 1){
        cout << "Impossible de revenir en arrière" << endl;
        return;
    }

    ifstream fic(fichier);

    string lignes[100];   // tableau fixe
    int n = 0;
    string ligne;

    // lecture de toutes les lignes
    while(fic >> ligne){
        lignes[n] = ligne;
        n++;
    }

    fic.close();

    // on "supprime" la dernière ligne en diminuant n
    n--;
    (*nb_positions)--;

    // réécriture du fichier (sans la dernière ligne)
    ofstream fic2(fichier);

    for(int i = 0; i < n; i++){
        fic2 << lignes[i] << endl;
    }

    fic2.close();

    // recharger la dernière position restante
    read_FEN(Plateau, lignes[n-1]);
}
