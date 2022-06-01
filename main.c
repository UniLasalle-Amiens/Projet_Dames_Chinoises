#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#include "lib/struct.h"
#include "lib/couleurs.h"
#include "lib/utilities.h"

#include "lib/initJoueurs.h"
#include "lib/afficherPlateau.h"
#include "lib/afficherInfoTourJoueur.h"
#include "lib/modifierPosition.h"
#include "lib/win.h"
#include "lib/mvtPossible.h"
#include "lib/game.h"


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