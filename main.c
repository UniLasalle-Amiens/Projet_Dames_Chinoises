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
void clear () {
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
            if( plateau[x][y].Char != 'z' ){              //vérification du caractère
                switch ( plateau [ x ] [ y ].couleur ) {
                    case 'R':
                        printf ( "[ " );
                        Color ( ROUGE, NOIR );
                        printf( "%c" , plateau[x][y].Char);
                        Color ( BLANC, NOIR );
                        printf ( " ] " );
                        break;
                    
                    case 'B':
                        printf ( "[ " );
                        Color ( BLEU_FONCE, NOIR );
                        printf( "%c" , plateau[x][y].Char);
                        Color ( BLANC, NOIR );
                        printf ( " ] " );
                        break;
                    
                    case 'J':
                        printf ( "[ " );
                        Color ( JAUNE, NOIR );
                        printf( "%c" , plateau[x][y].Char);
                        Color ( BLANC, NOIR );
                        printf ( " ] " );
                        break;

                    case 'O':
                        printf ( "[ " );
                        Color ( ORANGE, NOIR );
                        printf( "%c" , plateau[x][y].Char);
                        Color ( BLANC, NOIR );
                        printf ( " ] " );
                        break;

                    case 'V':
                        printf ( "[ " );
                        Color ( VERT_FONCE, NOIR );
                        printf( "%c" , plateau[x][y].Char);
                        Color ( BLANC, NOIR );
                        printf ( " ] " );
                        break;

                    case 'T':
                        printf ( "[ " );
                        Color ( TURQUOISE, NOIR );
                        printf( "%c" , plateau[x][y].Char);
                        Color ( BLANC, NOIR );
                        printf ( " ] " );
                        break;

                    default:
                        printf( "[ %c ] " , plateau[x][y].Char);
                }
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
 * @param plateau {pion}
 * @param numPion  {integer}
 * @param direction {char}
 * @param *j {joueur} - joueur ayant joué
 * 
 * @return void
 */
void modifierPosition ( pion plateau [ 13 ] [ 17 ], int numPion, char direction, joueur *j ) {
    // L'ancienne case hérite de attributs de la nouvelle sur laquelle le pion à été bougé
    plateau [ j->pions [ numPion ].x ] [ j->pions [ numPion ].y ].couleur = ' ';

    switch ( direction ) {
        case 'a':
            // Case pair en y donc on décale aussi en x car les cases sont décalées une sur deux
            if ( j->pions [ numPion ].y % 2 == 0 ) { // Vérification de la case en y paire
                j->pions [ numPion ].x -= 1;
                j->pions [ numPion ].y -= 1;
            } else
                j->pions [ numPion ].y -= 1;

            break;
    }
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

    switch ( nbj ) {
        case 2: // Quand il y a 2 joueurs
            for ( int i = 0 ; i < nbj ; i++ )
                for ( int k = 0 ; k < NB_PIONS ; k++ ) {
                    switch ( i ) {
                        case 0:
                            if ( j [ i ].pions [ NB_PIONS ].x == 6 || j [ i ].pions [ NB_PIONS ].x == 5 || j [ i ].pions [ NB_PIONS ].x == 4 || j [ i ].pions [ NB_PIONS ].x == 7 && j [ i ].pions [ NB_PIONS ].y == 0 || j [ i ].pions [ NB_PIONS ].y == 1 || j [ i ].pions [ NB_PIONS ].y == 2 || j [ i ].pions [ NB_PIONS ].y == 3 ) {
                                *numJoueurGagnant = i + 1;
                                retour = true;
                            }
                            
                            break;
                        
                        case 1:
                            if ( j [ i ].pions [ NB_PIONS ].x == 6 || j [ i ].pions [ NB_PIONS ].x == 5 || j [ i ].pions [ NB_PIONS ].x == 4 || j [ i ].pions [ NB_PIONS ].x == 7 && j [ i ].pions [ NB_PIONS ].y == 16 || j [ i ].pions [ NB_PIONS ].y == 15 || j [ i ].pions [ NB_PIONS ].y == 14 || j [ i ].pions [ NB_PIONS ].y == 13 ) {
                                *numJoueurGagnant = i + 1;
                                retour = true;
                            }
                            break;
                    }
                }
            break;
    }
    return retour;
}


/**
 * @fn game
 * @brief Fonction de lancement du jeu
 * 
 * @param nb_joueurs  {integer}
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

    bool ask, gagnant = false, boolean;

    clear ();
    afficherPlateau ( nb_joueurs, joueurs, plateau );


    // Jeu
    while ( !gagnant ) { // Le jeu tourne tant qu'il n'y a pas de gagnant
        ask = true;

        while ( ask ) {
            afficherInfoTourJoueur ( joueurs, count );
            printf ( "\n\nQuel pion voulez-vous bouger ? : " );
            scanf ( "%d", &numPion );

            if ( numPion < 0 || numPion > 9 ) {
                clear ();
                printf ( "\nPion inexistant" );
                Sleep ( TIME );
                clear ();
                afficherPlateau ( nb_joueurs, joueurs, plateau );

                // Vérification par la suite si le pion peut bouger

            } else {
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
            printf ( "\n\nDans quelle direction voulez-vous vous deplacer ? : " );
            fflush ( stdin );
            scanf ( "%c", &askPosition );

            if ( askPosition != 'a' && askPosition != 'e' && askPosition != 'q' && askPosition != 'd' && askPosition != 'w' && askPosition != 'c' ) {
                clear ();
                printf ( "\nDirection inconnue" );
                Sleep ( TIME );
                clear ();
                afficherPlateau ( nb_joueurs, joueurs, plateau );

                // Vérification par la suite si ce mvt est possible

            } else {
                clear ();
                modifierPosition ( plateau, numPion, askPosition, &joueurs [ count - 1 ] );
                ask = false;
                break;
            }
        }

        clear ();
        afficherPlateau ( nb_joueurs, joueurs, plateau );

        count++;

        // if ( count > nb_joueurs ) {
        //     gagnant = true;
        //     break;
        // }

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