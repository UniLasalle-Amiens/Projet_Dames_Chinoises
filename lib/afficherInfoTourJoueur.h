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