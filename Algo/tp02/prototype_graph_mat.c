#include <stdio.h>
#include <stdlib.h>

struct graphe {
	unsigned n; /* ordre du graphe */
	unsigned *adj; /* matrice d'adjacence */
};

void afficher(struct graphe *g);

int main()
{
	unsigned n = 4;
	struct graphe *g = malloc(sizeof(struct graphe));

	g->n = n;
	g->adj = calloc(n * n, sizeof(unsigned));

	if (g == NULL || g->adj == NULL){
		perror("malloc");
		return EXIT_FAILURE;
	}

	g->adj[2 * n + 1] = g->adj[1 * n + 2] = 1;
	g->adj[0 * n + 3] = g->adj[3 * n + 0] = 1;
	g->adj[2 * n + 2] = 1;

	afficher(g);
	free(g->adj);
	free(g);
	return 0;
}

void afficher(struct graphe *g)
{
	unsigned v, w;
	for (v = 0; v < g->n; ++v)
		for (w = 0; w < g->n; ++w) {
			printf("%3u", g->adj[v * g->n + w]);
			if (w != g->n - 1)
				printf(" ");
			else
				printf("\n");
		}
}
