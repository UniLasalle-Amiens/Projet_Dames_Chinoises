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