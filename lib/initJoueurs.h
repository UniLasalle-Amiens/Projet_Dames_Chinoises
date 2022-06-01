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