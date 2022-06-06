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
    bool replay = false, sautPion = false;

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

            else if ( !mvtPossible ( plateau, &joueurs [ count - 1 ], numPion ) ) {
                clear ();
                printf ( "\nLe pion selectionne ne peut pas bouger" );
                Sleep ( TIME );
                clear ();
                afficherPlateau ( nb_joueurs, joueurs, plateau );
            }

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

            if ( replay )
                printf ( "\n\t\tr: rester a cet endroit" );

            printf ( "\n\nDans quelle direction voulez-vous vous deplacer ? (pions %d): ", numPion );
            fflush ( stdin );
            scanf ( "%c", &askPosition );

            if ( askPosition == 'r' && replay ) {
                ask = false;
                replay = false;
                break;
            }

            // Vérification de la saisie de l'utilisateur
            if ( askPosition != 'a' && askPosition != 'e' && askPosition != 'q' && askPosition != 'd' && askPosition != 'w' && askPosition != 'c' ) {
                clear ();
                printf ( "\nDirection inconnue" );
                Sleep ( TIME );
                clear ();
                afficherPlateau ( nb_joueurs, joueurs, plateau );
            
            // Empêche un joueur de jouer indéfiniment
            } else if ( askPosition == mvt ) {
                clear ();
                printf ( "\nImpossible de faire le mouvement de pion inverse" );
                printf ( "\nAttendez un tour !!" );
                Sleep ( TIME );
                clear ();
                afficherPlateau ( nb_joueurs, joueurs, plateau );
            }

            else {
                clear ();
                modifierPosition ( plateau, numPion, askPosition, &joueurs [ count - 1 ], &Case, &replay, &sautPion );
                
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
        if ( !replay ) {
            count++;
            mvt = 'n';
            sautPion = false;
        }

        if ( count > nb_joueurs )
            count = 1;


        // Gestion de la fin de partie
        boolean = win ( plateau, joueurs, nb_joueurs, &indexJoueurGagnant );

        if ( boolean ) {
            clear ();
            Color ( ROUGE, NOIR );
            printf ( "\n\n\tLE JOUEUR %d '%s' A GAGNE !!!", indexJoueurGagnant, joueurs [ indexJoueurGagnant - 1 ].nom );
            Color ( BLANC, NOIR );

            gagnant = true;
            break;
        }
    }
}