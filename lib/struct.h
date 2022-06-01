/**
 * @struct pion
 * @brief structure d'un pion du 
 *
 * @param {integer} x
 * @param {integer} y
 * @param Char {char}
 * @param couleur {char}
 */
typedef struct pion {
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
 * @param {integer} compteur
 * @param {pion} pions
 */
typedef struct joueur {
    char couleur;
    char nom [100];
    pion pions [ 10 ];
} joueur;