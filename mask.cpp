#include<iostream>
#include"types.hpp"
#include"board.hpp"
#include"view.hpp"

using namespace std;

// Fonction qui permet de creer un masque vide sans informations 
Mask empty_mask(){
    Mask m;
    for(int i=0 ; i<L;i++){
        for(int j=0 ; j<C ; j++){
            m.mask[i][j]=0;  // on initialise chaque case a 0
        }
    }
    return m; // on retourne le masque sans informations - initialise a 0 -
}


// Fontion qui reinitialise un masque deja existant a 0
void clear_mask(Mask *m){
    for(int i=0 ; i<L;i++){
        for(int j=0 ; j<C ; j++){
            m->mask[i][j]=0;  // on remet a 0 chauqe case du masque existant
        }
    }
     
}


//Fonction qui permet de lire le contenur d'une case du masque
int get_mask(Mask m , int l , int c){
    if (l < 0 || l >= L || c < 0 || c >= C){
        cout << "Erreur acces (" << l << "," << c << ")" << endl;
        return 0;  // on cas d'erreur c-a-d case invalide en retourne 0
    }
    int ContenuCase= m.mask[l][c];   
    return ContenuCase;   // on retourne le contenu de la case 
}


//Fonction qui permet de modifier le contenu d'une case du masque
void set_mask(Mask *m , int l , int c , int caseMask){
    if (l < 0 || l >= L || c < 0 || c >= C){
        cout << "Erreur ecriture (" << l << "," << c << ")" << endl;
        return ;  // on cas d'erreur c-a-d case invalide on retourne le masque tel qu'il est
    }
    m->mask[l][c]=caseMask;   // on modifie le contenu de la case souhaitee
    
}

//Fonction qui vérifie que la piece est blanc
bool est_blanc(square piece){
    if (piece >= 6 && piece <= 11 ) return true;
    return false;
}


//Fonction qui vérifie une case d'arrivé [y][x] est valide
bool move_valide(square Plateau2D[L][C], int y, int x, int l, int c){
    if ( y >= 0 && y <= 7 && x >= 0 && x <= 7 ){ //on vérifie que les case sont bien dans le plateau
        if ( Plateau2D[y][x] == vide || (est_blanc(Plateau2D[l][c]) != est_blanc(Plateau2D[y][x])) )
            return true;
    }
    return false;
}

//Fonction qui met en couleur bleu les mouvements possible pour le roi
void highlight_possible_move_king(square Plateau2D[L][C], Mask *m , int l , int c ){
    
    for (int y = l-1 ; y <= l+1 ; y++){
        for (int x = c-1 ; x <= c+1 ; x++){
            if (move_valide(Plateau2D, y, x, l, c)){
                        set_mask( m, y, x, 4);
            }
            set_mask(m, l, c, 5);
        }        
    }
}

//Fonction qui met en couleur bleu les mouvements possible pour la tour
void highlight_possible_move_rook(square Plateau2D[L][C], Mask *m , int l , int c ){
    set_mask(m, l, c, 5);
    int y = l, x = c;
    while (move_valide( Plateau2D, y-1 , x ,l ,c)){
        y--;
        set_mask( m, y, x, 4);
        if (Plateau2D[y][x] != vide)break;
    }
    y = l;

    while (move_valide( Plateau2D, y+1 , x ,l ,c)){
        y++;
        set_mask( m, y, x, 4);
        if (Plateau2D[y][x] != vide)break;
    }
    y = l;

    while (move_valide( Plateau2D, y , x-1 ,l ,c)){
        x--;
        set_mask( m, y, x, 4);
        if (Plateau2D[y][x] != vide) break;
    }
    x = c;

    while (move_valide( Plateau2D, y , x+1 ,l ,c)){
        x++;
        set_mask( m, y, x, 4);
        if (Plateau2D[y][x] != vide)break;
    }
    x = c;


}

//Fonction qui met en couleur bleu les mouvements possible pour le fou
void highlight_possible_move_bishop(square Plateau2D[L][C], Mask *m , int l , int c ){
    set_mask(m, l, c, 5);
    int y = l, x = c;
    while (move_valide( Plateau2D, y-1 , x-1 ,l ,c)){
        y--;
        x--;
        set_mask( m, y, x, 4);
        if (Plateau2D[y][x] != vide)break;
    }
    y = l;
    x = c;

    while (move_valide( Plateau2D, y+1 , x-1 ,l ,c)){
        y++;
        x--;
        set_mask( m, y, x, 4);
        if (Plateau2D[y][x] != vide)break;
    }
    y = l;
    x = c;

    while (move_valide( Plateau2D, y-1 , x+1 ,l ,c)){
        y--;
        x++;
        set_mask( m, y, x, 4);
        if (Plateau2D[y][x] != vide) break;
    }
    y = l;
    x = c;

    while (move_valide( Plateau2D, y+1 , x+1 ,l ,c)){
        y++;
        x++;
        set_mask( m, y, x, 4);
        if (Plateau2D[y][x] != vide)break;
    }
    y = l;
    x = c;


}

//Fonction qui met en couleur bleu les mouvements possible pour la dame
void highlight_possible_move_queen(square Plateau2D[L][C], Mask *m , int l , int c ){
    set_mask(m, l, c, 5);
    int y = l, x = c;

    //partie movement en ligne et colonne
    while (move_valide( Plateau2D, y-1 , x ,l ,c)){
        y--;
        set_mask( m, y, x, 4);
        if (Plateau2D[y][x] != vide)break;
    }
    y = l;

    while (move_valide( Plateau2D, y+1 , x ,l ,c)){
        y++;
        set_mask( m, y, x, 4);
        if (Plateau2D[y][x] != vide)break;
    }
    y = l;

    while (move_valide( Plateau2D, y , x-1 ,l ,c)){
        x--;
        set_mask( m, y, x, 4);
        if (Plateau2D[y][x] != vide) break;
    }
    x = c;

    while (move_valide( Plateau2D, y , x+1 ,l ,c)){
        x++;
        set_mask( m, y, x, 4);
        if (Plateau2D[y][x] != vide)break;
    }
    x = c;

    //partie movement en diagonal
    while (move_valide( Plateau2D, y-1 , x-1 ,l ,c)){
        y--;
        x--;
        set_mask( m, y, x, 4);
        if (Plateau2D[y][x] != vide)break;
    }
    y = l;
    x = c;

    while (move_valide( Plateau2D, y+1 , x-1 ,l ,c)){
        y++;
        x--;
        set_mask( m, y, x, 4);
        if (Plateau2D[y][x] != vide)break;
    }
    y = l;
    x = c;

    while (move_valide( Plateau2D, y-1 , x+1 ,l ,c)){
        y--;
        x++;
        set_mask( m, y, x, 4);
        if (Plateau2D[y][x] != vide) break;
    }
    y = l;
    x = c;

    while (move_valide( Plateau2D, y+1 , x+1 ,l ,c)){
        y++;
        x++;
        set_mask( m, y, x, 4);
        if (Plateau2D[y][x] != vide)break;
    }
    y = l;
    x = c;


}

//Fonction qui met en couleur bleu les mouvements possible pour le cavalier
void highlight_possible_move_knight(square Plateau2D[L][C], Mask *m , int l , int c ){
    set_mask(m, l, c, 5);
    int y = l, x = c;

    if ( Plateau2D[y-2][x] == vide && move_valide(Plateau2D, y-2, x-1, l, c)){
        set_mask( m, y-2, x-1, 4);
    }
            
    if ( Plateau2D[y-2][x] == vide && move_valide(Plateau2D, y-2, x+1, l, c)){
        set_mask( m, y-2, x+1, 4);
    }

    if ( Plateau2D[y+2][x] == vide && move_valide(Plateau2D, y+2, x-1, l, c)){
        set_mask( m, y+2, x-1, 4);
    }

    if ( Plateau2D[y+2][x] == vide && move_valide(Plateau2D, y+2, x+1, l, c)){
        set_mask( m, y+2, x+1, 4);
    }

    if ( Plateau2D[y][x-2] == vide && move_valide(Plateau2D, y-1, x-2, l, c)){
        set_mask( m, y-1, x-2, 4);
    }

    if ( Plateau2D[y][x-2] == vide && move_valide(Plateau2D, y+1, x-2, l, c)){
        set_mask( m, y+1, x-2, 4);
    }

    if ( Plateau2D[y][x+2] == vide && move_valide(Plateau2D, y-1, x+2, l, c)){
        set_mask( m, y-1, x+2, 4);
    }

    if ( Plateau2D[y][x+2] == vide && move_valide(Plateau2D, y+1, x+2, l, c)){
        set_mask( m, y+1, x+2, 4);
    }


}


//Fonction qui met en couleur bleu les mouvements possible pour le pion
void highlight_possible_move_pawn(square Plateau2D[L][C], Mask *m , int l , int c ){
    set_mask(m, l, c, 5);
    int y = l, x = c;

    //deplacement pion blanc
    if (est_blanc(Plateau2D[l][c])){

        if ( l == 1 && Plateau2D[l+1][c] == vide && Plateau2D[l+2][c] == vide ) set_mask( m, y+2, x, 4);

        for (int i = x-1; i <= x+1 ; i++){
            if ( y >= 0 && y <= 7 && x >= 0 && x <= 7 ){
                if ( i == x ){
                    if (Plateau2D[l+1][c] == vide) set_mask(m, y+1, i, 4);
                }
                else if ( Plateau2D[l+1][i] != vide && !est_blanc(Plateau2D[y+1][i])) set_mask(m, y+1, i, 4);
            }
        }

    }
    //deplacement pion noir
    else{
        if ( l == 6 && Plateau2D[l-1][c] == vide && Plateau2D[l-2][c] == vide ) set_mask( m, y-2, x, 4);
        for (int i = x-1; i <= x+1 ; i++){
            if ( y >= 0 && y <= 7 && x >= 0 && x <= 7 ){
                if ( i == x ){
                    if (Plateau2D[l-1][c] == vide) set_mask(m, y-1, i, 4);
                }
                else if ( Plateau2D[l-1][i] != vide && est_blanc(Plateau2D[y-1][i])) set_mask(m, y-1, i, 4);
            }
        }
    }

}

//fonction qui verifie le type de pion et qui fait appel à la fonction qui correspond
void highlight_possible_move(square Plateau2D[L][C],Mask *m, int l , int c){
    square piece = get_square_2D( Plateau2D, l , c );
    if (piece != vide){ 
        if ( piece == Ntour || piece == Btour) highlight_possible_move_rook(Plateau2D, m , l , c);
        if ( piece == Ncavalier || piece == Bcavalier) highlight_possible_move_knight(Plateau2D, m , l , c );
        if ( piece == Nfou || piece == Bfou) highlight_possible_move_bishop(Plateau2D, m , l , c );
        if ( piece == Ndame || piece == Bdame) highlight_possible_move_queen(Plateau2D, m , l , c );
        if ( piece == Nroi || piece == Broi) highlight_possible_move_king(Plateau2D, m , l , c );
        if ( piece == Npion || piece == Bpion) highlight_possible_move_pawn (Plateau2D, m , l , c );
    }
}


void highlight_moveble_pieces(square Plateau2D[L][C],Mask *m, bool blanc){
    Mask m_tmp;
        
    for(int i=0 ; i<L;i++){
        for(int j=0 ; j<C ; j++){

            if (est_blanc(Plateau2D[i][j]) == blanc ){
                highlight_possible_move(Plateau2D, &m_tmp, i  , j );

                for(int y=0 ; y<L;y++){
                    for(int x=0 ; x<C ; x++){
                        if (get_mask(m_tmp,y,x) == 4) set_mask( m, i, j, 6 );

                    }
                }
                clear_mask( &m_tmp);
            }
        }
    }
    print_board_color( Plateau2D , *m);
}


void highlight_attacked_pieces(square Plateau2D[L][C],Mask *m, bool blanc){
    Mask m_tmp;
    // erreur pour l'affichage
    for(int i=0 ; i<L;i++){
        for(int j=0 ; j<C ; j++){

            if (est_blanc(Plateau2D[i][j]) == blanc ){
                if (Plateau2D[i][j] == Bpion || Plateau2D[i][j] == Npion ){

                highlight_possible_move(Plateau2D, &m_tmp, i  , j );

                for(int y=0 ; y<L;y++){
                    for(int x=0 ; x<C ; x++){
                        if (get_mask(m_tmp,y,x) == 4 && j != x ) set_mask( m, y, x, 1 );
                        if (est_blanc(Plateau2D[y][x]) != blanc && get_mask(*m,y,x) != 1 && Plateau2D[y][x] != vide) set_mask( m, y, x, 2 );
                    }
                }

                clear_mask( &m_tmp);
                }
                else{
                highlight_possible_move(Plateau2D, &m_tmp, i  , j );

                for(int y=0 ; y<L;y++){
                    for(int x=0 ; x<C ; x++){
                        if (get_mask(m_tmp,y,x) == 4 && Plateau2D[y][x] != vide) set_mask( m, y, x, 1 );
                        if (get_mask(m_tmp,y,x) != 4 && est_blanc(Plateau2D[y][x]) != blanc && get_mask(*m,y,x) != 1 && Plateau2D[y][x] != vide) set_mask( m, y, x, 2 );

                    }
                }
                clear_mask( &m_tmp);
                }

            }
        }
    }
    print_board_color( Plateau2D , *m);
}


void highlight_take_pieces(square Plateau2D[L][C],Mask *m, bool blanc){
    Mask m_tmp;
        
    for(int i=0 ; i<L;i++){
        for(int j=0 ; j<C ; j++){

            if (est_blanc(Plateau2D[i][j]) != blanc ){
                if (Plateau2D[i][j] == Bpion || Plateau2D[i][j] == Npion ){

                highlight_possible_move(Plateau2D, &m_tmp, i  , j );

                for(int y=0 ; y<L;y++){
                    for(int x=0 ; x<C ; x++){
                        if (get_mask(m_tmp,y,x) == 4 && j != x ){
                            set_mask( m, y, x, 1 );
                            set_mask( m, i, j, 7 );
                        }
                    }
                }
                clear_mask( &m_tmp);
                }
                else{
                highlight_possible_move(Plateau2D, &m_tmp, i  , j );

                for(int y=0 ; y<L;y++){
                    for(int x=0 ; x<C ; x++){
                        if (get_mask(m_tmp,y,x) == 4 && Plateau2D[y][x] != vide){
                        set_mask( m, y, x, 1 );
                        set_mask( m, i, j, 7 ); 
                        }
                        
                    }
                }
                clear_mask( &m_tmp);
                }

            }
        }
    }
    print_board_color( Plateau2D , *m);
}

void mask_choices_menu(){
    cout << "-----Menu-----" << endl
    << "0 -> afficher toutes vos pièces qui peuvent se déplacer au prochain coup" << endl
    << "1 -> afficher toutes les pièces adverse pouvent être prises au prochain coup" << endl
    << "2 -> afficher toutes les pièces adverse dangereuses à vos pièce" << endl
    << "3 -> afficher les déplacement possible d'une de vos pièce" << endl
    << "4 -> arrêter la consultation" << endl;

}

void mask_choices(square Plateau2D[L][C],Mask *m){
    int n;
    cout << "saisir un numéro : ";
    cin >> n;
    cout << endl;
    while (n != 4){
        if (n == 0){
            int x;
            cout << "saisir votre couleur, 0 pour blanc, 1 pour noir : ";
            cin >> x;
            cout << endl;
            if (x == 0) highlight_moveble_pieces(Plateau2D, m, true);
            else if (x == 1) highlight_moveble_pieces(Plateau2D, m, false);
            clear_mask( m );
        }
        if (n == 1){
            int x;
            cout << "saisir votre couleur, 0 pour blanc, 1 pour noir : ";
            cin >> x;
            cout << endl;
            if (x == 0) highlight_attacked_pieces(Plateau2D, m, true);
            else if (x == 1) highlight_attacked_pieces(Plateau2D, m, false);
            clear_mask( m );
        }
        if (n == 2){
            int x;
            cout << "saisir votre couleur, 0 pour blanc, 1 pour noir : ";
            cin >> x;
            cout << endl;
            if (x == 0) highlight_take_pieces(Plateau2D, m, true);
            else if (x == 1) highlight_take_pieces(Plateau2D, m, false);
            clear_mask( m );
        }
        if (n == 3){
            int y, x;
            cout << "saisir le coordonné de la pièce, ligne et colonne : ";
            cin >> y;
            cin >> x;
            cout << endl;
            highlight_possible_move(Plateau2D, m, y-1,x-1);
            print_board_color( Plateau2D , *m);
            clear_mask( m );
        }
        cout << "saisir un numéro : ";
        cin >> n;
        cout << endl;
    }
}