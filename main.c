#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>


// Enumération des constantes
#define ARRAY_LENGTH( array ) ( sizeof ( array ) / sizeof ( *array ) )

#define TIME 2500

#define NB_PIONS 10

#define NOIR 0
#define BLEU_FONCE 1
#define VERT_FONCE 2
#define TURQUOISE 3
#define ROUGE_FONCE 4
#define VIOLET 5
#define GRIS_CLAIR 7
#define ROUGE 12
#define JAUNE 14
#define BLANC 15

/**
 * @struct pion
 * @brief structure d'un pion du 
 * 
 * @param {integer} num
 * @param {integer} x
 * @param {integer} y
 */
typedef struct pion {
    int num;
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
 * @param {pion} pions
 */
typedef struct joueur {
    char couleur;
    char nom [100];
    pion pions [ 10 ];
} joueur;


/**
 * @fn Color
 * @brief Fonction permettant de mettre de la couleur
 * 
 * @param couleurDuTexte {integer}
 * @param couleurDeFond {integer}
 * @return void 
 */
void Color( int couleurDuTexte, int couleurDeFond ) // fonction d'affichage de couleurs
{
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
    system ( "cls" );
}


/**
 * @brief 
 * 
 * @param nb_joueurs {integer}
 * @param j {joueur}
 * 
 * @return integer 
 */
int afficherMenu ( int *nb_joueurs, joueur j [6] ) {
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
                    player.pions [ i ].num = i;
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
                    player.pions [ i ].num = i;
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
                break;

            case 4:
                player.couleur = 'O';
                break;
            
            case 5:
                player.couleur = 'V';
                break;

            case 6:
                player.couleur = 'M';
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
 * @return void 
 */
void afficherPlateau ( int nbj, joueur j [ 6 ] ) {
    //initialisation de variables

    int x, y, i, b;
    pion plateau [13][17];

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
            plateau [ j [ jx ].pions [ px ].x ] [ j [ jx ].pions [ px ].y ].Char = j [ jx ].pions [ px ].num + '0';
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
 * @fn game
 * @brief Fonction de lancement du jeu
 * 
 * @param nb_joueurs  {integer}
 * @param joueurs {joueur}
 * @return void 
 */
void game ( int nb_joueurs, joueur joueurs [6] ) {

    int i;
    int y;
    clear ();
    afficherPlateau ( nb_joueurs, joueurs );
}


// Fonction principal du programme
int main ( void ) {
    int menu;
    int nb_joueurs;
    joueur joueurs [6];

    clear ();
    Color ( VIOLET, NOIR );
    printf ( "*****" );
    Color ( JAUNE, NOIR );
    printf ( "          BIENVENUE SUR LES DAMES CHINOISES" );
    Color ( VIOLET, NOIR );
    printf ( "          *****" );
    Color ( BLANC, NOIR );

    menu = afficherMenu ( &nb_joueurs, joueurs );

    switch ( menu ) {
        case 1:
            game ( nb_joueurs, joueurs );
            break;
    }


    printf ( "\n\n" );
    system ( "PAUSE" );
    return EXIT_SUCCESS;
}