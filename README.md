# Jeu des Dames Chinoises

> Projet de programmation C réalisé par BREBION Mathis

Le programme utilise la library <windows.h> qui n'est disponible que sur les platformes WINDOWS.
Cette librairie est utilisée pour l'affichage des couleurs dans la console WINDOWS.

********************************************************
### Améliorations à venir

* Utilisation de l'encodage ANSI pour l'affichage des couleurs
* Rendre le programme fonctionnel sous système MAC et LINUX
** Utilisation de directives préprocesseur afin de rendre la compilation et l'exécution possible sous environnement LINUX et MAC
** Vidage manuel du tampon d'entrée pour les saisies clavier afin de pallier les éventuels bugs de la fonction fflush() sur les environnements LINUX