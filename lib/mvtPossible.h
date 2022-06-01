/**
 * @fn mvtPossible
 * @brief Fonction permettant de vérifier si un pion est jouable ou non
 * 
 * @param p [] [] {pion}
 * @param *j {joueur}
 * @param numPion {integer}
 * @return boolean
 */
bool mvtPossible ( pion p [ 13 ] [ 17 ], joueur *j, int numPion ) {
    int x = 0, y = 0;
    bool retour;

    for ( int i = 0 ; i < 12 ; i++ ) {
        switch ( i ) {
            
            // 1 case en diagonal direction a
            case 0:
                if ( j->pions [ numPion ].y % 2 == 0 ) {
                    x = -1;
                    y = -1;

                } else
                    y = -1;
                break;
            
            // 1 case en diagonal direction e
            case 1:
                if ( j->pions [ numPion ].y % 2 == 0 )
                    y = -1;

                else {
                    y = -1;
                    x = 1;
                }
                break;
            
            // 2 cases en diagonal direction a
            case 2:
                x = -1;
                y = -2;
                break;
            
            // 2 cases en diagonal direction e
            case 3:
                x = 1;
                y = -2;
                break;

            // 1 case direction q
            case 4:
                x = -1;
                y = 0;
                break;
            
            // 2 cases direction q
            case 5:
                x = -2;
                y = 0;
                break;

            // 1 case direction d
            case 6:
                x = 1;
                y = 0;
                break;
            
            // 2 cases direction d
            case 7:
                x = 2;
                y = 0;
                break;

            // 1 case direction w
            case 8:
                if ( j->pions [ numPion ].y % 2 == 0 ) {
                    x = -1;
                    y = 1;

                } else
                    y = 1;
                break;

            // 2 cases direction w
            case 9:
                x = -1;
                y = 2;
                break;

            // 1 case direction c
            case 10:
                if ( j->pions [ numPion ].y % 2 == 0 )
                    y = 1;

                else {
                    y = 1;
                    x = 1;
                }
                break;

            // 2 cases direction c
            case 11:
                x = 1;
                y = 2;
                break;
        }

        if ( p [ j->pions [ numPion ].x + x ] [ j->pions [ numPion ].y + y ].Char != 'x' )
            retour = false;

        else {
            retour = true;
            break;
        }
    }
    
    return retour;
}