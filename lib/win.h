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