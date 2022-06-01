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