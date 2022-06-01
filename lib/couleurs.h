// Définission des couleurs
#define NOIR 0
#define BLEU_FONCE 1
#define VERT_FONCE 2
#define TURQUOISE 3
#define ORANGE 13
#define VIOLET 5
#define GRIS_CLAIR 7
#define ROUGE 12
#define JAUNE 14
#define BLANC 15


/**
 * @fn Color
 * @brief Fonction permettant de changer la couleur de la console
 * 
 * @param couleurDuTexte {integer}
 * @param couleurDeFond {integer}
 * @return void 
 */
void Color( int couleurDuTexte, int couleurDeFond ) {
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}