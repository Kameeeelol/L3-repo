#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "graphe-4.h"

int main()
{

    graphe g;
    char *nom_fichier = "k4.dot";
    char cmd[100] = "dot -Tx11 ";

    graphe_complet(&g, 4, 0);

    graphe_ecrire_dot(&g, nom_fichier, 1);

    strcat(cmd, nom_fichier);
    system(cmd);

    graphe_detruire(&g);




    return EXIT_SUCCESS;
}
