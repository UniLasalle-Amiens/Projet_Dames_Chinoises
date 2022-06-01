// Enumération des constantes
#define ARRAY_LENGTH( array ) ( sizeof ( array ) / sizeof ( *array ) )

#define TIME 2500

// "cls" pour windows et "clear" pour MAC, LINUX
#define CLEAR "cls"

#define NB_PIONS 10


/**
 * @fn clear
 * @brief Permet de nettoyer la console
 * 
 * @return void 
 */
void clear ( void ) {
    system ( CLEAR );
}