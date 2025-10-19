#include "graph_mat-1.h"
#include <stdio.h>

#define ORDRE 10
#define PROBA 0.2

int main()
{
  char fichier[20];
  graph_mat * g[ORDRE];
  g[0] = gm_init(ORDRE);
  g[1] = gm_random(ORDRE, PROBA);

  printf("Matrice d'adjacence du graphe initial :\n");
  gm_disp(g[1]);
  gm_write_dot(g[1], "chemins-01.dot");
  
  for (int k=2; k<ORDRE; ++k)
    {
      g[k] = gm_prod(g[k - 1], g[1]);

      printf("Matrice d'adjacence des chemins de longueurs %d :\n", k);
      gm_disp(g[k]);
      sprintf(fichier, "chemins-%02d.dot", k);
      gm_write_dot(g[k], fichier);
    }
// Somme des matrices pour chemins <= k
    graph_mat *S = gm_init(ORDRE);
    for (int k = 1; k < ORDRE; ++k) {
        graph_mat *tmp = gm_sum(S, g[k]);
        gm_free(S);
        S = tmp;
    }

    printf("Matrice d'adjacence des chemins de longueur <= %d :\n", ORDRE-1);
    gm_disp(S);
    gm_write_dot(S, "chemins-somme.dot");

    // Clôture transitive : booléanisation de S
    graph_mat *closure = gm_init(ORDRE);
    for (int i = 0; i < ORDRE * ORDRE; ++i) {
        closure->adj[i] = (S->adj[i] > 0) ? 1 : 0;
    }
    printf("Cloture transitive :\n");
    gm_disp(closure);
    gm_write_dot(closure, "cloture.dot");

    // Calcul des distances minimales
    int dist[ORDRE][ORDRE];
    for (int i = 0; i < ORDRE; ++i) {
        for (int j = 0; j < ORDRE; ++j) {
            dist[i][j] = -1; // -1 signifie pas de chemin trouvé
            for (int k = 1; k < ORDRE; ++k) {
                if (g[k]->adj[i * ORDRE + j] > 0) {
                    dist[i][j] = k;
                    break;
                }
            }
        }
    }

    printf("Distances minimales entre sommets :\n");
    for (int i = 0; i < ORDRE; ++i) {
        for (int j = 0; j < ORDRE; ++j) {
            if (dist[i][j] < 0)
                printf("Inf ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }

    // Calcul du diamètre (distance maximale finie)
    int diameter = 0;
    for (int i = 0; i < ORDRE; ++i) {
        for (int j = 0; j < ORDRE; ++j) {
            if (dist[i][j] > diameter)
                diameter = dist[i][j];
        }
    }
    printf("Diamètre du graphe : %d\n", diameter);


  /* libération de la mémoire */
  for (int k=0; k<ORDRE; ++k)
    {
      gm_free(g[k]);
    }
  return 0;
}
