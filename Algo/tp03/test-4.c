#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "graphe-4.h"

int main()
{
    graphe g;
    int n = 5;
    int v, w;
    char *nom_fichier = "non_oriente.dot";
    char cmd[100] = "dot -Tx11 ";

    graphe_stable(&g, 5, 0);
    graphe_ajouter_arete(&g, 0, 1, 3.7);
    graphe_ajouter_arete(&g, 0, 1, 18.);
    graphe_ajouter_arete(&g, 1, 2, -1.);
    graphe_ajouter_arete(&g, 1, 1, 1.3);
    graphe_ajouter_arete(&g, 3, 0, .5);
    graphe_ajouter_arete(&g, 0, 4, 2.1);
    graphe_ajouter_arete(&g, 4, 3, -.5);
    graphe_ajouter_arete(&g, 4, 2, 10.3);
    
    puts("Matrice d'adjacence du graphe");
    for (v = 0; v < n; ++v) {
	    for (w = 0; w < n; ++w)
		    printf("%d ", graphe_get_multiplicite_arete(&g, v, w));
	    puts("");
    }

    puts("Degrés sortants");
    for (v = 0; v < n; ++v)
	    printf("%d ", graphe_get_degre_sortant(&g, v));
    puts(" ");

    puts("Degrés entrants");
    for (v = 0; v < n; ++v)
	    printf("%d ", graphe_get_degre_entrant(&g, v));
    puts(" ");

    puts("Degrés");
    for (v = 0; v < n; ++v)
	    printf("%d ", graphe_get_degre(&g, v));
    puts(" ");


    graphe_ecrire_dot(&g, nom_fichier, 1);
    strcat(cmd, nom_fichier);
    system(cmd);

    graphe_detruire(&g);
    return EXIT_SUCCESS;
}
