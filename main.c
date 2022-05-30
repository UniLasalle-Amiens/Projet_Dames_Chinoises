#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>


// Enumération des constantes
#define ARRAY_LENGTH( array ) ( sizeof ( array ) / sizeof ( *array ) )

#define TIME 2500

// "cls" pour windows et "clear" pour MAC, LINUX
#define CLEAR "cls"

#define NB_PIONS 10

// Définission des couleurs
#define NOIR 0
#define BLEU_FONCE 1
#define VERT_FONCE 2
#define TURQUOISE 3
#define ORANGE 13
#define VIOLET 5
#define GRIS_CLAIR 7
#define ROUGE 12
#define JAUNE 14
#define BLANC 15

/**
 * @struct pion
 * @brief structure d'un pion du 
 *
 * @param {integer} x
 * @param {integer} y
 * @param Char {char}
 * @param couleur {char}
 */
typedef struct pion {
    int x;
    int y;
    char Char;
    char couleur;
} pion;

/**
 * @struct joueur
 * @brief structure d'un joueur du jeu
 * 
 * @param {char} couleur
 * @param {char} nom []
 * @param {integer} compteur
 * @param {pion} pions
 */
typedef struct joueur {
    char couleur;
    char nom [100];
    pion pions [ 10 ];
} joueur;


/**
 * @fn Color
 * @brief Fonction permettant de changer la couleur de la console
 * 
 * @param couleurDuTexte {integer}
 * @param couleurDeFond {integer}
 * @return void 
 */
void Color( int couleurDuTexte, int couleurDeFond ) {
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

/**
 * @fn clear
 * @brief Permet de nettoyer la console
 * 
 * @return void 
 */
void clear ( void ) {
    system ( CLEAR );
}


/**
 * @fn initJoueur
 * @brief permet d'initialiser les joueurs de la partie
 * 
 * @param *nb_joueurs {integer}
 * @param j {joueur}
 * 
 * @return integer 
 */
int initJoueur ( int *nb_joueurs, joueur j [6] ) {
    int retour = 0;
    bool loop = true;
    int count = 1;
    char chaine [100];

    joueur player;
    pion pions;

    while ( loop ) {
        Color ( TURQUOISE, NOIR );
        printf ( "\n\nVeuillez choisir le nombre de joueur: " );
        scanf ( "%d", nb_joueurs );
        Color ( BLANC, NOIR );

        if ( *nb_joueurs < 2 || *nb_joueurs > 6 ) {
            printf ( "\nIl faut un minimum de 2 joueurs et un maximum de 6 joueurs" );
            Sleep ( TIME );
            clear ();
        } else {
            loop = false;
            break;
        }
    }

    while ( count <= *nb_joueurs ) {
        Color ( TURQUOISE, NOIR );
        printf ( "\n\nVeuillez entrer le nom du joueur %d: ", count );
        fflush ( stdin );
        scanf ( "%s", chaine );
        Color ( BLANC, NOIR );

        strcpy ( player.nom, chaine );

        switch ( count ) {
            case 1:
                player.couleur = 'R';

                for ( int i = 0 ; i < 10 ; i++ ) {
                    player.pions [ i ].Char = i + '0';
                    player.pions [ i ].couleur = player.couleur;
                }

                player.pions [ 0 ].x = 6;
                player.pions [ 0 ].y = 16;

                player.pions [ 1 ].x = 5;
                player.pions [ 1 ].y = 15;

                player.pions [ 2 ].x = 6;
                player.pions [ 2 ].y = 15;

                player.pions [ 3 ].x = 5;
                player.pions [ 3 ].y = 14;

                player.pions [ 4 ].x = 6;
                player.pions [ 4 ].y = 14;

                player.pions [ 5 ].x = 7;
                player.pions [ 5 ].y = 14;
                
                player.pions [ 6 ].x = 4;
                player.pions [ 6 ].y = 13;

                player.pions [ 7 ].x = 5;
                player.pions [ 7 ].y = 13;

                player.pions [ 8 ].x = 6;
                player.pions [ 8 ].y = 13;

                player.pions [ 9 ].x = 7;
                player.pions [ 9 ].y = 13;
                break;
            
            case 2:
                player.couleur = 'B';

                for ( int i = 0 ; i < 10 ; i++ ) {
                    player.pions [ i ].Char = i + '0';
                    player.pions [ i ].couleur = player.couleur;
                }

                player.pions [ 0 ].x = 6;
                player.pions [ 0 ].y = 0;

                player.pions [ 1 ].x = 5;
                player.pions [ 1 ].y = 1;

                player.pions [ 2 ].x = 6;
                player.pions [ 2 ].y = 1;

                player.pions [ 3 ].x = 5;
                player.pions [ 3 ].y = 2;

                player.pions [ 4 ].x = 6;
                player.pions [ 4 ].y = 2;

                player.pions [ 5 ].x = 7;
                player.pions [ 5 ].y = 2;
                
                player.pions [ 6 ].x = 4;
                player.pions [ 6 ].y = 3;

                player.pions [ 7 ].x = 5;
                player.pions [ 7 ].y = 3;

                player.pions [ 8 ].x = 6;
                player.pions [ 8 ].y = 3;

                player.pions [ 9 ].x = 7;
                player.pions [ 9 ].y = 3;
                break;

            case 3:
                player.couleur = 'J';

                for ( int i = 0 ; i < 10 ; i++ ) {
                    player.pions [ i ].Char = i + '0';
                    player.pions [ i ].couleur = player.couleur;
                }

                player.pions [ 0 ].x = 0;
                player.pions [ 0 ].y = 12;

                player.pions [ 1 ].x = 0;
                player.pions [ 1 ].y = 11;

                player.pions [ 2 ].x = 1;
                player.pions [ 2 ].y = 12;

                player.pions [ 3 ].x = 1;
                player.pions [ 3 ].y = 10;

                player.pions [ 4 ].x = 1;
                player.pions [ 4 ].y = 11;

                player.pions [ 5 ].x = 2;
                player.pions [ 5 ].y = 12;
                
                player.pions [ 6 ].x = 1;
                player.pions [ 6 ].y = 9;

                player.pions [ 7 ].x = 2;
                player.pions [ 7 ].y = 10;

                player.pions [ 8 ].x = 2;
                player.pions [ 8 ].y = 11;

                player.pions [ 9 ].x = 3;
                player.pions [ 9 ].y = 12;
                break;

            case 4:
                player.couleur = 'O';

                for ( int i = 0 ; i < 10 ; i++ ) {
                    player.pions [ i ].Char = i + '0';
                    player.pions [ i ].couleur = player.couleur;
                }

                player.pions [ 0 ].x = 12;
                player.pions [ 0 ].y = 4;

                player.pions [ 1 ].x = 11;
                player.pions [ 1 ].y = 4;

                player.pions [ 2 ].x = 11;
                player.pions [ 2 ].y = 5;

                player.pions [ 3 ].x = 10;
                player.pions [ 3 ].y = 4;

                player.pions [ 4 ].x = 10;
                player.pions [ 4 ].y = 5;

                player.pions [ 5 ].x = 11;
                player.pions [ 5 ].y = 6;
                
                player.pions [ 6 ].x = 9;
                player.pions [ 6 ].y = 4;

                player.pions [ 7 ].x = 9;
                player.pions [ 7 ].y = 5;

                player.pions [ 8 ].x = 10;
                player.pions [ 8 ].y = 6;

                player.pions [ 9 ].x = 10;
                player.pions [ 9 ].y = 7;
                break;
            
            case 5:
                player.couleur = 'V';

                for ( int i = 0 ; i < 10 ; i++ ) {
                    player.pions [ i ].Char = i + '0';
                    player.pions [ i ].couleur = player.couleur;
                }

                player.pions [ 0 ].x = 12;
                player.pions [ 0 ].y = 12;

                player.pions [ 1 ].x = 11;
                player.pions [ 1 ].y = 11;

                player.pions [ 2 ].x = 11;
                player.pions [ 2 ].y = 12;

                player.pions [ 3 ].x = 11;
                player.pions [ 3 ].y = 10;

                player.pions [ 4 ].x = 10;
                player.pions [ 4 ].y = 11;

                player.pions [ 5 ].x = 10;
                player.pions [ 5 ].y = 12;
                
                player.pions [ 6 ].x = 10;
                player.pions [ 6 ].y = 9;

                player.pions [ 7 ].x = 10;
                player.pions [ 7 ].y = 10;

                player.pions [ 8 ].x = 9;
                player.pions [ 8 ].y = 11;

                player.pions [ 9 ].x = 9;
                player.pions [ 9 ].y = 12;
                break;

            case 6:
                player.couleur = 'T';

                for ( int i = 0 ; i < 10 ; i++ ) {
                    player.pions [ i ].Char = i + '0';
                    player.pions [ i ].couleur = player.couleur;
                }

                player.pions [ 0 ].x = 0;
                player.pions [ 0 ].y = 4;

                player.pions [ 1 ].x = 1;
                player.pions [ 1 ].y = 4;

                player.pions [ 2 ].x = 0;
                player.pions [ 2 ].y = 5;

                player.pions [ 3 ].x = 2;
                player.pions [ 3 ].y = 4;

                player.pions [ 4 ].x = 1;
                player.pions [ 4 ].y = 5;

                player.pions [ 5 ].x = 1;
                player.pions [ 5 ].y = 6;
                
                player.pions [ 6 ].x = 3;
                player.pions [ 6 ].y = 4;

                player.pions [ 7 ].x = 2;
                player.pions [ 7 ].y = 5;

                player.pions [ 8 ].x = 2;
                player.pions [ 8 ].y = 6;

                player.pions [ 9 ].x = 1;
                player.pions [ 9 ].y = 7;
                break;
        }

        j [ count - 1 ] = player;

        count++;
    }

    retour = 1;

    return retour;
}


/**
 * @fn afficherPlateau
 * @brief Fonction permettant d'afficher le plateau de jeu
 * 
 * @param nbj {integer}
 * @param j {joueur}
 * @param plateau [][] {pion}
 * @return void 
 */
void afficherPlateau ( int nbj, joueur j [ 6 ], pion plateau [ 13 ] [ 17 ] ) {
    //initialisation de variables

    int x, y, i, b;

// remplissage du plateau
// remplie la totalité du tableau par 'z'

    for( y=0 ; y<17 ; y++ ){
        for( x=0 ; x<13 ; x++ ){
            plateau[x][y].Char = 'z';
        }
    }

//  remplace 'z' par 'x' pour délimiter le plateau
// Etoile
    plateau[6][0].Char='x';
    for(b=5;b<7;b++){plateau[b][1].Char= 'x';}
    for(b=5;b<8;b++){plateau[b][2].Char='x';}
    for(b=4;b<8;b++){plateau[b][3].Char='x';}

    for(b=0;b<13;b++){plateau[b][4].Char='x';}
    for(b=0;b<12;b++){plateau[b][5].Char='x';}
    for(b=1;b<12;b++){plateau[b][6].Char='x';}
    for(b=1;b<11;b++){plateau[b][7].Char='x';}
    for(b=2;b<11;b++){plateau[b][8].Char='x';}
    for(b=1;b<11;b++){plateau[b][9].Char='x';}
    for(b=1;b<12;b++){plateau[b][10].Char='x';}
    for(b=0;b<12;b++){plateau[b][11].Char='x';}
    for(b=0;b<13;b++){plateau[b][12].Char='x';}

    for(b=4;b<8;b++){plateau[b][13].Char= 'x';}
    for(b=5;b<8;b++){plateau[b][14].Char='x';}
    for(b=5;b<7;b++){plateau[b][15].Char='x';}
    plateau[6][16].Char='x';

    // Remplissage du tableau "plateau" par les chiffres des pions des différent joueurs
    for ( int jx = 0 ; jx < nbj ; jx++ ) {
        for ( int px = 0 ; px < NB_PIONS ; px++ ) {
            plateau [ j [ jx ].pions [ px ].x ] [ j [ jx ].pions [ px ].y ].Char = j [ jx ].pions [ px ].Char;
            plateau [ j [ jx ].pions [ px ].x ] [ j [ jx ].pions [ px ].y ].couleur = j [ jx ].pions [ px ].couleur;
        }
    }


//affichage du tableau

    i = 0;
    for( y=0 ; y<17 ; y++ ){ //boucle ligne
        i++;
        if( i % 2 == 0 ){ //décalage de la ligne une ligne sur deux
            printf("   ");
        }
        for( x=0 ; x<13 ; x++ ){ //boucle colone
            if( plateau[x][y].Char != 'z' ){ //vérification du caractère
                printf ( "[ " );

                switch ( plateau [ x ] [ y ].couleur ) {
                    case 'R':
                        Color ( ROUGE, NOIR );
                        break;
                    
                    case 'B':
                        Color ( BLEU_FONCE, NOIR );
                        break;
                    
                    case 'J':
                        Color ( JAUNE, NOIR );
                        break;

                    case 'O':
                        Color ( ORANGE, NOIR );
                        break;

                    case 'V':
                        Color ( VERT_FONCE, NOIR );
                        break;

                    case 'T':
                        Color ( TURQUOISE, NOIR );
                        break;
                }

                printf( "%c" , plateau[x][y].Char);
                Color ( BLANC, NOIR );
                printf ( " ] " );
            }                                       
            else{                                   //si caractère != 'z' -> afficher le caractère correspondant 
                printf("      ");}                  //permet la délimitaion du plateau lors de son affichage
        }
        printf("\n\n");
        
    }
}

/**
 * @fn afficherInfoTourJoueur
 * @brief Afficher le joueur qui doit actuellement jouer
 * 
 * @param j [] {joueur}
 * @param count {integer}
 * @return void
 */
void afficherInfoTourJoueur ( joueur j [], int count ) {
    printf ( "\n\nJoueur %d, a vous de jouer ", count );
        
    // Affichage du nom du joueur en fonction de sa couleur d'équipe
    switch ( j [ count - 1 ].couleur ) {
        case 'R':
            Color ( ROUGE, NOIR );
            break;

        case 'B':
            Color ( BLEU_FONCE, NOIR );
            break;
        
        case 'J':
            Color ( JAUNE, NOIR );
            break;
        
        case 'O':
            Color ( ORANGE, NOIR );
            break;
        
        case 'V':
            Color ( VERT_FONCE, NOIR );
            break;
        
        case 'T':
            Color ( TURQUOISE, NOIR );
            break;
    }
    printf ( "'%s'", j [ count - 1 ].nom );
    Color ( BLANC, NOIR );
}

/**
 * @fn modifierPosition
 * @brief Permet de modifier la position des pions sur le plateau
 * 
 * @param p {pion}
 * @param numPion  {integer}
 * @param direction {char}
 * @param *j {joueur} - joueur ayant joué
 * @param *value {char}
 * @param *replay {boolean} joueur doit rejouer ? (après un saut de pion)
 * 
 * @return void
 */
void modifierPosition ( pion p [ 13 ] [ 17 ], int numPion, char direction, joueur *j, char *value, bool *replay ) {
    int x, y, x2, y2 = 0;

    switch ( direction ) {
        case 'a':

            // Case pair en y donc on décale aussi en x car les cases sont décalées une sur deux
            if ( j->pions [ numPion ].y % 2 == 0 ) { // Vérification de la case en y paire
                // j->pions [ numPion ].x -= 1;
                // j->pions [ numPion ].y -= 1;

                x = -1;
                y = -1;

            } else
                y = -1;
                // j->pions [ numPion ].y -= 1;

            // Saut d'un pion
            if ( p [ j->pions [ numPion ].x + x ] [ j->pions [ numPion ].y + y ].Char != 'x' ) {
                x = -1;
                y = -2;

                *replay = true;

            } else
                *replay = false;
            break;

        case 'e':
            if ( j->pions [ numPion ].y % 2 == 0 )
                y = -1;
                // j->pions [ numPion ].y -= 1;

            else {
                y = -1;
                x = 1;
                // j->pions [ numPion ].y -= 1;
                // j->pions [ numPion ].x += 1;
            }

            // Saut d'un pion
            if ( p [ j->pions [ numPion ].x + x ] [ j->pions [ numPion ].y + y ].Char != 'x' ) {
                x = 1;
                y = -2;

                *replay = true;

            } else
                *replay = false;
            break;
        
        case 'd':
            x = 1;
            y = 0;
            // j->pions [ numPion ].x += 1;

            // Saut d'un pion
            if ( p [ j->pions [ numPion ].x + x ] [ j->pions [ numPion ].y + y ].Char != 'x' ) {
                x = 2;
                *replay = true;

            } else
                *replay = false;

            break;
        
        case 'q':
            x = -1;
            y = 0;
            // j->pions [ numPion ].x -= 1;

            // Saut d'un pion
            if ( p [ j->pions [ numPion ].x + x ] [ j->pions [ numPion ].y + y ].Char != 'x' ) {
                x = -2;
                *replay = true;

            } else
                *replay = false;

            break;

        case 'w':
            if ( j->pions [ numPion ].y % 2 == 0 ) {
                x = -1;
                y = 1;
                // j->pions [ numPion ].x -= 1;
                // j->pions [ numPion ].y += 1;

            } else
                y = 1;
                // j->pions [ numPion ].y += 1;

            // Saut d'un pion
            if ( p [ j->pions [ numPion ].x + x ] [ j->pions [ numPion ].y + y ].Char != 'x' ) {
                x = -1;
                y = 2;
                
                *replay = true;

            } else
                *replay = false;
            break;

        case 'c':
            if ( j->pions [ numPion ].y % 2 == 0 )
                y = 1;
                // j->pions [ numPion ].y += 1;
            
            else {
                y = 1;
                x = 1;
                // j->pions [ numPion ].y += 1;
                // j->pions [ numPion ].x += 1;
            }

            // Saut d'un pion
            if ( p [ j->pions [ numPion ].x + x ] [ j->pions [ numPion ].y + y ].Char != 'x' ) {
                x = 1;
                y = 2;
                
                *replay = true;

            } else
                *replay = false;
            break;
    }

    // On vérifie si le pion ne sort pas du plateau
    if ( p [ j->pions [ numPion ].x + x ] [ j->pions [ numPion ].y + y ].Char != 'z' && p [ j->pions [ numPion ].x + x ] [ j->pions [ numPion ].y + y ].Char == 'x') {

        // L'ancienne case hérite de attributs de la nouvelle sur laquelle le pion à été bougé
        p [ j->pions [ numPion ].x ] [ j->pions [ numPion ].y ].couleur = ' ';

        j->pions [ numPion ].x += x;
        j->pions [ numPion ].y += y;

        *value = 'c'; // Le pion ne sort pas du plateau et peut se déplacer sur la bonne case
    
    // On vérifie si le pion ne va pas sauter deux pions
    } else if ( p [ j->pions [ numPion ].x + x ] [ j->pions [ numPion ].y + y ].Char != 'x' && p [ j->pions [ numPion ].x + x ] [ j->pions [ numPion ].y + y ].Char != 'z' ) {
        *value = 'r'; // Le pion saute deux pions

    } else
        *value = 'z'; // Le pion sort du plateau

}


/**
 * @fn win
 * @brief Fonction permettant de finir la partie
 * 
 * @param p {pion}
 * @param j {joueur}
 * @param nbj {integer}
 * @param *numJoueurGagnant {integer}
 * 
 * @return boolean
 */
bool win ( pion p [ 13 ] [ 17 ], joueur j [], int nbj, int *numJoueurGagnant ) {
    bool retour;

    // En fonction du nombre d'équipe on vient vérifié si chaque pion d'une équipe se situe bien dans les cases du camp adverse
    switch ( nbj ) {
        case 2: // Quand il y a 2 joueurs
            if ( p [ 6 ] [ 0 ].couleur == 'R' && p [ 5 ] [ 1 ].couleur == 'R' && p [ 6 ] [ 1 ].couleur == 'R' && p [ 5 ] [ 2 ].couleur == 'R' && p [ 6 ] [ 2 ].couleur == 'R' && p [ 7 ] [ 2 ].couleur == 'R' && p [ 4 ] [ 3 ].couleur == 'R' && p [ 5 ] [ 3 ].couleur == 'R' && p [ 6 ] [ 3 ].couleur == 'R' && p [ 7 ] [ 3 ].couleur == 'R') {
                retour = true;
                *numJoueurGagnant = 1;

            } else if ( p [ 6 ] [ 16 ].couleur == 'B' && p [ 5 ] [ 15 ].couleur == 'B' && p [ 6 ] [ 15 ].couleur == 'B' && p [ 5 ] [ 14 ].couleur == 'B' && p [ 6 ] [ 14 ].couleur == 'B' && p [ 7 ] [ 14 ].couleur == 'B' && p [ 4 ] [ 13 ].couleur == 'B' && p [ 5 ] [ 13 ].couleur == 'B' && p [ 6 ] [ 13 ].couleur == 'B' && p [ 7 ] [ 13 ].couleur == 'B') {
                retour = true;
                *numJoueurGagnant = 2;
            }
            break;

        case 3: // 3 joueurs
            if ( p [ 6 ] [ 0 ].couleur == 'R' && p [ 5 ] [ 1 ].couleur == 'R' && p [ 6 ] [ 1 ].couleur == 'R' && p [ 5 ] [ 2 ].couleur == 'R' && p [ 6 ] [ 2 ].couleur == 'R' && p [ 7 ] [ 2 ].couleur == 'R' && p [ 4 ] [ 3 ].couleur == 'R' && p [ 5 ] [ 3 ].couleur == 'R' && p [ 6 ] [ 3 ].couleur == 'R' && p [ 7 ] [ 3 ].couleur == 'R') {
                retour = true;
                *numJoueurGagnant = 1;

            } else if ( p [ 6 ] [ 16 ].couleur == 'B' && p [ 5 ] [ 15 ].couleur == 'B' && p [ 6 ] [ 15 ].couleur == 'B' && p [ 5 ] [ 14 ].couleur == 'B' && p [ 6 ] [ 14 ].couleur == 'B' && p [ 7 ] [ 14 ].couleur == 'B' && p [ 4 ] [ 13 ].couleur == 'B' && p [ 5 ] [ 13 ].couleur == 'B' && p [ 6 ] [ 13 ].couleur == 'B' && p [ 7 ] [ 13 ].couleur == 'B') {
                retour = true;
                *numJoueurGagnant = 2;

            } else if ( p [ 12 ] [ 4 ].couleur == 'J' && p [ 11 ] [ 4 ].couleur == 'J' && p [ 11 ] [ 5 ].couleur == 'J' && p [ 10 ] [ 4 ].couleur == 'J' && p [ 10 ] [ 5 ].couleur == 'J' && p [ 11 ] [ 6 ].couleur == 'J' && p [ 9 ] [ 4 ].couleur == 'J' && p [ 9 ] [ 5 ].couleur == 'J' && p [ 10 ] [ 6 ].couleur == 'J' && p [ 10 ] [ 7 ].couleur == 'J') {
                retour = true;
                *numJoueurGagnant = 3;
            }
            break;

        case 4: // 4 joueurs
            if ( p [ 6 ] [ 0 ].couleur == 'R' && p [ 5 ] [ 1 ].couleur == 'R' && p [ 6 ] [ 1 ].couleur == 'R' && p [ 5 ] [ 2 ].couleur == 'R' && p [ 6 ] [ 2 ].couleur == 'R' && p [ 7 ] [ 2 ].couleur == 'R' && p [ 4 ] [ 3 ].couleur == 'R' && p [ 5 ] [ 3 ].couleur == 'R' && p [ 6 ] [ 3 ].couleur == 'R' && p [ 7 ] [ 3 ].couleur == 'R') {
                retour = true;
                *numJoueurGagnant = 1;

            } else if ( p [ 6 ] [ 16 ].couleur == 'B' && p [ 5 ] [ 15 ].couleur == 'B' && p [ 6 ] [ 15 ].couleur == 'B' && p [ 5 ] [ 14 ].couleur == 'B' && p [ 6 ] [ 14 ].couleur == 'B' && p [ 7 ] [ 14 ].couleur == 'B' && p [ 4 ] [ 13 ].couleur == 'B' && p [ 5 ] [ 13 ].couleur == 'B' && p [ 6 ] [ 13 ].couleur == 'B' && p [ 7 ] [ 13 ].couleur == 'B') {
                retour = true;
                *numJoueurGagnant = 2;

            } else if ( p [ 12 ] [ 4 ].couleur == 'J' && p [ 11 ] [ 4 ].couleur == 'J' && p [ 11 ] [ 5 ].couleur == 'J' && p [ 10 ] [ 4 ].couleur == 'J' && p [ 10 ] [ 5 ].couleur == 'J' && p [ 11 ] [ 6 ].couleur == 'J' && p [ 9 ] [ 4 ].couleur == 'J' && p [ 9 ] [ 5 ].couleur == 'J' && p [ 10 ] [ 6 ].couleur == 'J' && p [ 10 ] [ 7 ].couleur == 'J') {
                retour = true;
                *numJoueurGagnant = 3;

            } else if ( p [ 0 ] [ 12 ].couleur == 'O' && p [ 0 ] [ 11 ].couleur == 'O' && p [ 1 ] [ 12 ].couleur == 'O' && p [ 1 ] [ 10 ].couleur == 'O' && p [ 1 ] [ 11 ].couleur == 'O' && p [ 2 ] [ 12 ].couleur == 'O' && p [ 1 ] [ 9 ].couleur == 'O' && p [ 2 ] [ 10 ].couleur == 'O' && p [ 2 ] [ 11 ].couleur == 'O' && p [ 3 ] [ 12 ].couleur == 'O') {
                retour = true;
                *numJoueurGagnant = 4;
            }
            break;

        case 5: // 5 joueurs
            if ( p [ 6 ] [ 0 ].couleur == 'R' && p [ 5 ] [ 1 ].couleur == 'R' && p [ 6 ] [ 1 ].couleur == 'R' && p [ 5 ] [ 2 ].couleur == 'R' && p [ 6 ] [ 2 ].couleur == 'R' && p [ 7 ] [ 2 ].couleur == 'R' && p [ 4 ] [ 3 ].couleur == 'R' && p [ 5 ] [ 3 ].couleur == 'R' && p [ 6 ] [ 3 ].couleur == 'R' && p [ 7 ] [ 3 ].couleur == 'R') {
                retour = true;
                *numJoueurGagnant = 1;

            } else if ( p [ 6 ] [ 16 ].couleur == 'B' && p [ 5 ] [ 15 ].couleur == 'B' && p [ 6 ] [ 15 ].couleur == 'B' && p [ 5 ] [ 14 ].couleur == 'B' && p [ 6 ] [ 14 ].couleur == 'B' && p [ 7 ] [ 14 ].couleur == 'B' && p [ 4 ] [ 13 ].couleur == 'B' && p [ 5 ] [ 13 ].couleur == 'B' && p [ 6 ] [ 13 ].couleur == 'B' && p [ 7 ] [ 13 ].couleur == 'B') {
                retour = true;
                *numJoueurGagnant = 2;

            } else if ( p [ 12 ] [ 4 ].couleur == 'J' && p [ 11 ] [ 4 ].couleur == 'J' && p [ 11 ] [ 5 ].couleur == 'J' && p [ 10 ] [ 4 ].couleur == 'J' && p [ 10 ] [ 5 ].couleur == 'J' && p [ 11 ] [ 6 ].couleur == 'J' && p [ 9 ] [ 4 ].couleur == 'J' && p [ 9 ] [ 5 ].couleur == 'J' && p [ 10 ] [ 6 ].couleur == 'J' && p [ 10 ] [ 7 ].couleur == 'J') {
                retour = true;
                *numJoueurGagnant = 3;

            } else if ( p [ 0 ] [ 12 ].couleur == 'O' && p [ 0 ] [ 11 ].couleur == 'O' && p [ 1 ] [ 12 ].couleur == 'O' && p [ 1 ] [ 10 ].couleur == 'O' && p [ 1 ] [ 11 ].couleur == 'O' && p [ 2 ] [ 12 ].couleur == 'O' && p [ 1 ] [ 9 ].couleur == 'O' && p [ 2 ] [ 10 ].couleur == 'O' && p [ 2 ] [ 11 ].couleur == 'O' && p [ 3 ] [ 12 ].couleur == 'O') {
                retour = true;
                *numJoueurGagnant = 4;

            } else if ( p [ 0 ] [ 4 ].couleur == 'V' && p [ 1 ] [ 4 ].couleur == 'V' && p [ 0 ] [ 5 ].couleur == 'V' && p [ 2 ] [ 4 ].couleur == 'V' && p [ 1 ] [ 5 ].couleur == 'V' && p [ 1 ] [ 6 ].couleur == 'V' && p [ 3 ] [ 4 ].couleur == 'V' && p [ 2 ] [ 5 ].couleur == 'V' && p [ 2 ] [ 6 ].couleur == 'V' && p [ 1 ] [ 7 ].couleur == 'V') {
                retour = true;
                *numJoueurGagnant = 5;
            }
            break;

        case 6:
            if ( p [ 6 ] [ 0 ].couleur == 'R' && p [ 5 ] [ 1 ].couleur == 'R' && p [ 6 ] [ 1 ].couleur == 'R' && p [ 5 ] [ 2 ].couleur == 'R' && p [ 6 ] [ 2 ].couleur == 'R' && p [ 7 ] [ 2 ].couleur == 'R' && p [ 4 ] [ 3 ].couleur == 'R' && p [ 5 ] [ 3 ].couleur == 'R' && p [ 6 ] [ 3 ].couleur == 'R' && p [ 7 ] [ 3 ].couleur == 'R') {
                retour = true;
                *numJoueurGagnant = 1;

            } else if ( p [ 6 ] [ 16 ].couleur == 'B' && p [ 5 ] [ 15 ].couleur == 'B' && p [ 6 ] [ 15 ].couleur == 'B' && p [ 5 ] [ 14 ].couleur == 'B' && p [ 6 ] [ 14 ].couleur == 'B' && p [ 7 ] [ 14 ].couleur == 'B' && p [ 4 ] [ 13 ].couleur == 'B' && p [ 5 ] [ 13 ].couleur == 'B' && p [ 6 ] [ 13 ].couleur == 'B' && p [ 7 ] [ 13 ].couleur == 'B') {
                retour = true;
                *numJoueurGagnant = 2;

            } else if ( p [ 12 ] [ 4 ].couleur == 'J' && p [ 11 ] [ 4 ].couleur == 'J' && p [ 11 ] [ 5 ].couleur == 'J' && p [ 10 ] [ 4 ].couleur == 'J' && p [ 10 ] [ 5 ].couleur == 'J' && p [ 11 ] [ 6 ].couleur == 'J' && p [ 9 ] [ 4 ].couleur == 'J' && p [ 9 ] [ 5 ].couleur == 'J' && p [ 10 ] [ 6 ].couleur == 'J' && p [ 10 ] [ 7 ].couleur == 'J') {
                retour = true;
                *numJoueurGagnant = 3;

            } else if ( p [ 0 ] [ 12 ].couleur == 'O' && p [ 0 ] [ 11 ].couleur == 'O' && p [ 1 ] [ 12 ].couleur == 'O' && p [ 1 ] [ 10 ].couleur == 'O' && p [ 1 ] [ 11 ].couleur == 'O' && p [ 2 ] [ 12 ].couleur == 'O' && p [ 1 ] [ 9 ].couleur == 'O' && p [ 2 ] [ 10 ].couleur == 'O' && p [ 2 ] [ 11 ].couleur == 'O' && p [ 3 ] [ 12 ].couleur == 'O') {
                retour = true;
                *numJoueurGagnant = 4;

            } else if ( p [ 0 ] [ 4 ].couleur == 'V' && p [ 1 ] [ 4 ].couleur == 'V' && p [ 0 ] [ 5 ].couleur == 'V' && p [ 2 ] [ 4 ].couleur == 'V' && p [ 1 ] [ 5 ].couleur == 'V' && p [ 1 ] [ 6 ].couleur == 'V' && p [ 3 ] [ 4 ].couleur == 'V' && p [ 2 ] [ 5 ].couleur == 'V' && p [ 2 ] [ 6 ].couleur == 'V' && p [ 1 ] [ 7 ].couleur == 'V') {
                retour = true;
                *numJoueurGagnant = 5;

            } else if ( p [ 12 ] [ 12 ].couleur == 'T' && p [ 11 ] [ 11 ].couleur == 'T' && p [ 11 ] [ 12 ].couleur == 'T' && p [ 11 ] [ 10 ].couleur == 'T' && p [ 10 ] [ 11 ].couleur == 'T' && p [ 10 ] [ 12 ].couleur == 'T' && p [ 10 ] [ 9 ].couleur == 'T' && p [ 10 ] [ 10 ].couleur == 'T' && p [ 9 ] [ 11 ].couleur == 'T' && p [ 9 ] [ 12 ].couleur == 'T') {
                retour = true;
                *numJoueurGagnant = 6;
            }
            break;
    }
    return retour;
}


/**
 * @fn game
 * @brief Fonction de lancement du jeu
 * 
 * @param nb_joueurs {integer}
 * @param joueurs {joueur}
 * @param plateau [] [] {pion}
 * @param gagnant {bool}
 * @return void 
 */
void game ( int nb_joueurs, joueur joueurs [], pion plateau [ 13 ] [ 17 ] ) {
    int i, y;
    int count = 1;
    char askPosition;
    int numPion;
    int indexJoueurGagnant;

    char Case; // Variable servant à indiquer ou non à l'utilisateur si sa saisie fait sortir le pion du plateau
    char mvt = 'n'; // Variable servant à mettre en mémoire le mvt du joueur;

    bool ask, gagnant = false, boolean;
    bool replay = false;

    clear ();
    afficherPlateau ( nb_joueurs, joueurs, plateau );


    // Jeu
    while ( !gagnant ) { // Le jeu tourne tant qu'il n'y a pas de gagnant
        if ( replay )
            ask = false;
        else
            ask = true;

        while ( ask ) {
            afficherInfoTourJoueur ( joueurs, count );
            printf ( "\n\nQuel pion voulez-vous bouger ? : " );
            scanf ( "%d", &numPion );

            // Vérification de la saisie de l'utilisateur
            if ( numPion < 0 || numPion > 9 ) {
                clear ();
                printf ( "\nPion inexistant" );
                Sleep ( TIME );
                clear ();
                afficherPlateau ( nb_joueurs, joueurs, plateau );
            }

            // Vérification par la suite si le pion peut bouger

            else {
                ask = false;
                break;
            }
        }

        ask = true;

        while ( ask ) {
            clear ();
            afficherPlateau ( nb_joueurs, joueurs, plateau );
            afficherInfoTourJoueur ( joueurs, count );
            printf ( "\n" );
            printf ( "\n  \\    / " );
            printf ( "\n   a  e" );
            printf ( "\n-- q  d --");
            printf ( "\n   w  c" );
            printf ( "\n  /    \\ " );
            printf ( "\n\nDans quelle direction voulez-vous vous deplacer ? (pions %d): ", numPion );
            fflush ( stdin );
            scanf ( "%c", &askPosition );

            // Vérification de la saisie de l'utilisateur
            if ( askPosition != 'a' && askPosition != 'e' && askPosition != 'q' && askPosition != 'd' && askPosition != 'w' && askPosition != 'c' ) {
                clear ();
                printf ( "\nDirection inconnue" );
                Sleep ( TIME );
                clear ();
                afficherPlateau ( nb_joueurs, joueurs, plateau );
            
            // Empêche un joueur de jouer indéfiniment
            } else if ( mvt == askPosition ) {
                clear ();
                printf ( "\nImpossible de faire le mouvement de pion inverse" );
                printf ( "\nAttendez un tour !!" );
                Sleep ( TIME );
                clear ();
                afficherPlateau ( nb_joueurs, joueurs, plateau );
            }

            else {
                clear ();
                modifierPosition ( plateau, numPion, askPosition, &joueurs [ count - 1 ], &Case, &replay );
                
                // Vérification de la sortie de plateau ou non
                if ( Case == 'z' ) {
                    clear ();
                    printf ( "\nImpossible de sortir du plateau" );
                    Sleep ( TIME );
                    clear ();
                    afficherPlateau ( nb_joueurs, joueurs, plateau );

                // Vérification du saut de deux pions
                } else if ( Case == 'r' ) {
                    clear ();
                    printf ( "\nImpossible de sauter deux pions" );
                    Sleep ( TIME );
                    clear ();
                    afficherPlateau ( nb_joueurs, joueurs, plateau );
                
                // Mouvement possible
                } else {
                    ask = false;

                    switch ( askPosition ) {
                        case 'a':
                            mvt = 'c';
                            break;
                        
                        case 'e':
                            mvt = 'w';
                            break;

                        case 'q':
                            mvt = 'd';
                            break;

                        case 'd':
                            mvt = 'q';
                            break;
                    }
                    break;
                }
            }
        }

        clear ();
        afficherPlateau ( nb_joueurs, joueurs, plateau );

        // Le joueur rejoue tant qu'il fait des sauts de pion
        if ( !replay )
            count++;

        if ( count > nb_joueurs )
            count = 1;


        // Gestion de la fin de partie
        boolean = win ( plateau, joueurs, nb_joueurs, &indexJoueurGagnant );

        if ( boolean ) {
            clear ();
            Color ( ROUGE, NOIR );
            printf ( "\n\n\tLE JOUEUR %d '%s' A GAGNE !!!", indexJoueurGagnant + 1, joueurs [ indexJoueurGagnant ].nom );
            Color ( BLANC, NOIR );

            gagnant = true;
            break;
        }
    }
}


// Fonction principal du programme
int main ( void ) {
    int menu;
    int nb_joueurs;

    joueur joueurs [6];
    pion plateau [13][17];

    clear ();
    Color ( VIOLET, NOIR );
    printf ( "*****" );
    Color ( JAUNE, NOIR );
    printf ( "          BIENVENUE SUR LES DAMES CHINOISES" );
    Color ( VIOLET, NOIR );
    printf ( "          *****" );
    Color ( BLANC, NOIR );

    menu = initJoueur ( &nb_joueurs, joueurs );

    switch ( menu ) {
        case 1:
            game ( nb_joueurs, joueurs, plateau );
            break;
    }


    printf ( "\n\n" );
    system ( "PAUSE" );
    return EXIT_SUCCESS;
}