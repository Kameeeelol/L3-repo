#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "graphe-4.h"

int main()
{
    graphe g;
    char *nom_fichier = "oriente.dot";
    char cmd[100] = "dot -Tx11 ";

    graphe_stable(&g, 5, 1);
    printf("est_or = %d\n", g.est_or);
    graphe_ajouter_arc(&g, 0, 1, 3.7);
    graphe_ajouter_arc(&g, 0, 1, 18.);
    graphe_ajouter_arc(&g, 1, 2, -1.);
    graphe_ajouter_arc(&g, 1, 1, 1.3);
    graphe_ajouter_arc(&g, 3, 0, .5);
    graphe_ajouter_arc(&g, 0, 4, 2.1);
    graphe_ajouter_arc(&g, 4, 3, -.5);
    graphe_ajouter_arc(&g, 4, 2, 10.3);
   for (int v = 0; v < g.n; v++) {
    printf("Successeurs de %d :\n", v);
    msuc *p = g.tab_sucs[v];
    while (p) {
        printf("  %d -> %d (%f)\n", v, p->sommet, p->valeur);
        p = p->suivant;
    }
}



    graphe_ecrire_dot(&g, nom_fichier, 1);

    strcat(cmd, nom_fichier);
    system(cmd);

    graphe_detruire(&g);


    return EXIT_SUCCESS;
}
