#include<iostream>
#include <random>
#include"types.hpp"
#include"board.hpp"
#include"view.hpp"
#include"mask.hpp"
#include"historique.hpp"

using namespace std;

int alea(int a, int b){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<> dist(a,b);

    int val;
    val = dist(rng);
    return val;
}

// verifier si il y a echec
bool king_in_check(square Plateau[L][C], bool roi_blanc){

    Mask m_attack = empty_mask();

    // 1. Construire toutes les attaques adverses
    for(int i = 0; i < L; i++){
        for(int j = 0; j < C; j++){

            square p = Plateau[i][j];

            if(p == vide) continue;

            // pièces noires attaquent roi blanc
            if(roi_blanc){
                if(p == Ntour || p == Ncavalier || p == Nfou ||
                   p == Ndame || p == Npion){

                    highlight_possible_move(Plateau, &m_attack, i, j);
                }
            }

            // pièces blanches attaquent roi noir
            else{
                if(p == Btour || p == Bcavalier || p == Bfou ||
                   p == Bdame || p == Bpion){

                    highlight_possible_move(Plateau, &m_attack, i, j);
                }
            }
        }
    }

    // 2. Chercher le roi
    for(int i = 0; i < L; i++){
        for(int j = 0; j < C; j++){

            if(roi_blanc && Plateau[i][j] == Broi){
                return (get_mask(m_attack,i,j) == 4);
            }

            if(!roi_blanc && Plateau[i][j] == Nroi){
                return (get_mask(m_attack,i,j) == 4);
            }
        }
    }

    return false;
}

// choisi le mouvement pour l'ordinatuer en cas d'echec
bool choose_mouvement_king_in_check_computer(square Plateau[L][C], bool blanc){

    for(int i = 0; i < L; i++){
        for(int j = 0; j < C; j++){

            square p = Plateau[i][j];

            if(p == vide) continue;
            if(est_blanc(p) != blanc) continue;

            Mask m = empty_mask();
            highlight_possible_move(Plateau, &m, i, j);

            for(int y = 0; y < L; y++){
                for(int x = 0; x < C; x++){

                    if(get_mask(m,y,x) == 4){

                        square copy[L][C];
                        for(int a=0;a<L;a++)
                            for(int b=0;b<C;b++)
                                copy[a][b] = Plateau[a][b];

                        move_piece_2D(copy, i,j,y,x);

                        if(!king_in_check(copy, blanc)){
                            move_piece_2D(Plateau, i,j,y,x);
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false; // échec et mat potentiel
}

// verifie qu'un mouvement est possible
bool test_run(square Plateau[L][C], int l1, int c1 , int l2 , int c2 ){

    Mask m_tmp = empty_mask();
    highlight_possible_move(Plateau, &m_tmp, l1 , c1 );

    bool ok = (get_mask(m_tmp, l2, c2) == 4);
    
    clear_mask(&m_tmp);
    return ok;
}


void choose_mouvement_human(square Plateau[L][C], Mask *m, bool blanc){
    int l1, c1 , l2 , c2;
    char C1, C2;
    Mask m_tmp = empty_mask();

    cout << "entrer les coordonné de la pièce de départ : ";
    cin >> l1 >> C1 ;
    l1=l1-1;
    c1 = (int) C1 - 97 ;

    highlight_possible_move(Plateau, &m_tmp, l1 , c1 );
    print_board_color(Plateau , m_tmp);
    clear_mask(&m_tmp);
    
    while( est_blanc(Plateau[l1][c1] ) != blanc ){
        cout << "case vide ou pas de votre couleur , resaisir un coordonné : ";
        cin >> l1 >> C1 ;
        l1=l1-1;
        c1 = (int) C1 - 97 ;
        cout << endl;
        highlight_possible_move(Plateau, &m_tmp, l1 , c1 );
        print_board_color(Plateau , m_tmp);
        clear_mask(&m_tmp);
    }

    cout << endl << "entrer les coordonné de la case d'arrivé : ";
    cin >> l2 >> C2;
    l2=l2-1;
    c2 = (int) C2 - 97 ;

    while (test_run(Plateau, l1, c1 , l2 , c2) != true){
        cout << endl << "coordonné d'arrivé invalide ";
        cout << endl << "entrer les coordonné de la case d'arrivé : ";
        cin >> l2 >> C2;
        l2=l2-1;
        c2 = (int) C2 - 97 ;
    }

    clear_mask(m);
    move_piece_2D( Plateau, l1, c1, l2, c2);

    print_board_color(Plateau, *m); 
}

void one_run_human(square Plateau[L][C], Mask *m, bool blanc){ 
    cout << "pour consulter les masque , entrer '0', pour jouer votre coup, entrer '1' : " ;
    int x;
    cin >> x ;

    if (x == 0){
        mask_choices_menu();
        mask_choices( Plateau, m );
    }

    clear_mask(m); 
    choose_mouvement_human(Plateau, m, blanc);
}




void choose_mouvement_computer(square Plateau[L][C], Mask *m, int l, int c){ 
    bool fin = false;

    highlight_possible_move( Plateau, m, l, c);
    print_board_color(Plateau , *m);

    int n = 0;
    for(int i=0 ; i<L;i++){
        for(int j=0 ; j<C ; j++){
            if (get_mask(*m,i,j) == 4){ 
                n += 1;
            }
        }
    }

    int x = alea(1, n);
    int y = 0;

    for(int i=0 ; i<L;i++){
        for(int j=0 ; j<C ; j++){
            if (get_mask(*m,i,j) == 4){
                y += 1;
            }
            if (y == x){
                move_piece_2D(  Plateau, l , c , i ,j );
                fin = true;
                break;
            }
        }
        if (fin) break;
    }

    clear_mask(m);
}


void one_run_computer(square Plateau[L][C], Mask *m, bool blanc){ 

    highlight_moveble_pieces(Plateau, m, blanc);

    bool fin = false;
    int n = 0;

    for(int i=0 ; i<L;i++){
        for(int j=0 ; j<C ; j++){
            if (get_mask(*m,i,j) == 6){ 
                n += 1;
            }
        }
    }

    int x = alea(1, n);
    int y = 0;

    for(int i=0 ; i<L;i++){
        for(int j=0 ; j<C ; j++){
            if (get_mask(*m,i,j) == 6){
                y += 1;
            }
            if (y == x){
                clear_mask(m);
                choose_mouvement_computer(Plateau, m, i, j); 
                fin = true;
                break;
            }
        }
        if (fin) break;
    }

    clear_mask(m);
}



void one_run(square Plateau[L][C], Mask *m, bool human, bool blanc , int *nb_positions){ 
    if (human) one_run_human(Plateau, m, blanc);
    else one_run_computer(Plateau, m, blanc );

    string fichier = "FEN.txt";
    MAJ_historique(Plateau, fichier , nb_positions);
}

// la boucle de jeu principal, appellé depuis le main pour un jeu complet
void play_game(square Plateau[L][C]){
    int nb_positions=0;
    Mask m = empty_mask();

    bool blanc = true;

    while(true){

        print_board_color(Plateau, m);

        if(king_in_check(Plateau, blanc)){
            cout << "ROI EN ÉCHEC !" << endl;

            bool ok = choose_mouvement_king_in_check_computer(Plateau, blanc);

            if(!ok){
                cout << "ECHEC ET MAT !" << endl;

                if(blanc) cout << "Les noirs gagnent" << endl;
                else cout << "Les blancs gagnent" << endl;

                break;
            }
        }
        else{
            one_run(Plateau, &m, true, blanc, &nb_positions);
        }

        blanc = !blanc;
    }
}