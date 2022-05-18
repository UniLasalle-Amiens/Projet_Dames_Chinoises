#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define ARRAY_LENGTH( array ) ( sizeof ( array ) / sizeof ( *array ) )

#define TIME 2500

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

typedef struct pion {
    int num;
    int position;
    char couleur;
} pion;


typedef struct joueur {
    char couleur;
    char nom [100];
} joueur;


void Color( int couleurDuTexte, int couleurDeFond ) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void clear () {
    system ( "cls" );
}

int afficherMenu ( int *nb_joueurs, joueur j [6] ) {
    int retour = 0;
    bool loop = true;
    int count = 1;
    char chaine [100];

    joueur player;

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
                break;
            
            case 2:
                player.couleur = 'B';
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

void afficherPlateau ( int nbj, joueur j [ 6 ] ) {
    int lignes = 4;
}

void game ( int nb_joueurs, joueur joueurs [6] ) {
    int i;
    int y;
    clear ();
}

int main ( void ) {
    int menu;
    int nb_joueurs;
    joueur joueurs [6];
    pion pions [24];

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