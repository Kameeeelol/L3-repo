#include "graph_mat-1.h"
#include <stdio.h>

int main()
{
	graph_mat *g1 = gm_init(5);
	graph_mat *g2 = gm_init(5);

	gm_add_edge(g1, 0, 1);
    gm_add_edge(g1, 0, 4);
    gm_add_edge(g1, 1, 4);

    gm_add_edge(g2, 2, 2);
    gm_add_edge(g2, 2, 3);
    gm_add_edge(g2, 4, 1);

	printf("Graphe g1:\n");
    gm_disp(g1);
    printf("Graphe g2:\n");
    gm_disp(g2);

	for (unsigned v = 0; v < gm_n(g1); ++v) {
    printf("Degré du sommet %u : %u\n", v, gm_degree(g1, v));
	}

	for (unsigned v = 0; v < gm_n(g2); ++v) {
    printf("Degré du sommet %u : %u\n", v, gm_degree(g2, v));
	}

	graph_mat *g_sum = gm_sum(g1, g2);
	printf("Somme des graphes g1 + g2 :\n");
    gm_disp(g_sum);

	graph_mat *g_prod = gm_prod(g1, g2);
	printf("Produit des graphes g1 + g2 :\n");
    gm_disp(g_prod);

	gm_write_dot(g_prod, "test-1.dot");
	gm_free(g1);
	gm_free(g2);
	gm_free(g_sum);
	gm_free(g_prod);

	return 0;
}
