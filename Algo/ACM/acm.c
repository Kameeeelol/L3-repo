/**
 * \file acm.c
 * \brief Calcul et représentation d'arbres couvrant minimaux (implémentation)
 * \version 2
 * \date novembre 2020
 */
#include "acm.h"

#include <stdlib.h>
#include <stdio.h>
#include <float.h>

/*************** Prim */

graph_mat *gm_acm_prim(const graph_mat *g, unsigned depart)
{
	if (g == NULL) return NULL;
	int n = gm_n(g);
    if (n == 0) return NULL;
    
    // Allocation de l'arbre couvrant minimal
    graph_mat *acm = gm_init(n); // graphe non orienté
    if (!acm) return NULL;
    
    // Tableaux pour l'algorithme
    int *marque = (int *)calloc(n, sizeof(int)); // 0 = non marqué, 1 = marqué
    double *poids = (double *)malloc(n * sizeof(double));
    int *parent = (int *)malloc(n * sizeof(int));
    
    if (!marque || !poids || !parent) {
        if (marque) free(marque);
        if (poids) free(poids);
        if (parent) free(parent);
        gm_free(acm);
        return NULL;
    }
    
    // Initialisation
    for (int i = 0; i < n; i++) {
        marque[i] = 0;
        poids[i] = DBL_MAX;
        parent[i] = -1;
    }
    
    poids[depart] = 0.0;
    parent[depart] = depart;
    
    // Algorithme de Prim
    for (int iteration = 0; iteration < n; iteration++) {
        // Recherche du sommet non marqué de poids minimal
        int pivot = -1;
        double min_poids = DBL_MAX;
        
        for (int i = 0; i < n; i++) {
            if (!marque[i] && poids[i] < min_poids) {
                min_poids = poids[i];
                pivot = i;
            }
        }
        
        // Si aucun pivot trouvé, le graphe n'est pas connexe
        if (pivot == -1) {
            // Version bonus : on pourrait chercher un nouveau composant connexe
            free(marque);
            free(poids);
            free(parent);
            gm_free(acm);
            return NULL;
        }
        
        // Marquer le pivot
        marque[pivot] = 1;
        
        // Ajouter l'arête au ACM (sauf pour le sommet de départ)
        if (pivot != depart) {
            gm_add_edge(acm, pivot, parent[pivot], poids[pivot]);
        }
        
        // Mettre à jour les voisins non marqués
        for (int w = 0; w < n; w++) {
            if (!marque[w] && gm_mult_edge(g, pivot, w)) {
                double cout = gm_val_edge(g, pivot, w);
                if (cout < poids[w]) {
                    poids[w] = cout;
                    parent[w] = pivot;
                }
            }
        }
    }
    
    free(marque);
    free(poids);
    free(parent);
    
    return acm;

}

/*************** Kruskal */
/* type et fonctions auxiliaires pour Kruskal : ne pas modifier */

/**
 * \brief Type \a struct edge avec cout
 *
 * Une arête est représentée par ses deux extrémités :
 * \a v et \a w et sa valeur \a value
 * Pour l'unicité de la représentation, on supposera que
 * \f$ v \leq w \f$.
 * On accèdera directement aux champs de cette structure.
 */
struct edge {
	int v; /**<plus petite extrémité de l'arête */
	int w; /**<plus grande extrémité de l'arête */
	double value; /**<coût de l'arête */
};

/**
 * \brief Compare les arêtes par coût
 * \param e1 adresse de la première arête
 * \param e2 adresse de la deuxième arête
 * \return -1, 0 ou 1 selon que le coût de e1 est respectivement inférieur,
 * égal ou supérieur au coût de e2.
 *
 * Cette fonction n'est utilisée que par \a sort_edges et ne doit pas être
 * modifiée.
 */
static int cmp_edges(const void *e1, const void *e2)
{
	const struct edge *f1 = e1;
	const struct edge *f2 = e2;
	if (f1->value == f2->value)
		return 0;
	if (f1->value < f2->value)
		return -1;
	return 1;
}

/**
 * \brief Trie les arêtes du graph_mat par coût croissant
 * \param g adresse du graph_mat à lire
 * \return un pointeur vers un tableau des arêtes de g triées par coût
 * croissant. Les boucles sont supprimées et en cas d'arêtes multiple, seule
 * l'arête de plus petit coût est présente dans le tableau. Si l'allocation du
 * tableau a échoué, la valeur de retour est \a NULL.
 *
 * La fonction appelante devra libérer la mémoire allouée au tableau avec la
 * fonction \a free.
 */
static struct edge *sort_edges(const graph_mat *g)
{
	unsigned v, w, i = 0;
	struct edge *tab = malloc(gm_m(g) * sizeof(struct edge));
	if (!tab)
		return NULL;
	for (v = 0; v < gm_n(g); ++v)
		for (w = v + 1; w < gm_n(g); ++w)
			if (gm_mult_edge(g, v, w)) {
				tab[i].v = v;
				tab[i].w = w;
				tab[i].value = gm_val_edge(g, v, w);
				++i;
			}
	qsort(tab, i, sizeof(struct edge), cmp_edges);
	return tab;
}
/* Calcul de l'ACM par Kruskal : à remplir ! */

graph_mat *gm_acm_kruskal(const graph_mat *g)
{
	unsigned n = gm_n(g);
    if (n == 0) return NULL;

    graph_mat *acm = gm_init(n);
    if (!acm) return NULL;

    struct edge *edges = sort_edges(g);
    if (!edges) { gm_free(acm); return NULL; }

    /* Allocation Union-Find */
    int *parent = malloc(n * sizeof(int));
    int *rank   = malloc(n * sizeof(int));
    if (!parent || !rank) {
        free(edges);
        free(parent);
        free(rank);
        gm_free(acm);
        return NULL;
    }

    /* Init UF */
    for (unsigned i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }

    /* ------------------ Kruskal, tout ici ------------------ */
    unsigned m = gm_m(g);

    for (unsigned i = 0; i < m; ++i) {

        int v = edges[i].v;
        int w = edges[i].w;

        /* FIND(v) inline */
        int a = v;
        while (parent[a] != a)
            a = parent[a];

        /* FIND(w) inline */
        int b = w;
        while (parent[b] != b)
            b = parent[b];

        /* S'ils sont déjà connectés → ignore */
        if (a == b) continue;

        /* Sinon, ajoute cette arête dans l'ACM */
        gm_add_edge(acm, v, w, edges[i].value);

        /* UNION(a, b) inline */
        if (rank[a] < rank[b]) {
            parent[a] = b;
        }
        else if (rank[a] > rank[b]) {
            parent[b] = a;
        }
        else {
            parent[b] = a;
            rank[a]++;
        }
    }

    /* ------------------------------------------------------- */

    free(edges);
    free(parent);
    free(rank);

    return acm;
       
}

int gm_write_dot_with_mst(const graph_mat *g, const graph_mat *acm, const char *nom_fichier)
{
	unsigned u, v;
	FILE *f = fopen(nom_fichier, "w");
	if (!f) { perror("fopen"); return -1; }
	fputs("graph {\n", f);
	for (u = 0; u < gm_n(g); ++u)
		fprintf(f, "\t%d;\n", u);
	fputs("\n", f);
	fputs("\tsubgraph g {\n", f);
	for (u = 0; u < gm_n(g); ++u)
		for (v = u; v < gm_n(g); ++v)
			if (gm_mult_edge(g, u, v) &&
				( u == v || !gm_mult_edge(acm, u, v)))
					fprintf(f, "\t\t%d -- %d [label = %.2f];\n",
						u, v, gm_val_edge(g, u, v));
	fputs("\t}\n", f);
	fputs("\tsubgraph acm {\n\t\tedge [color = red]\n", f);
	for (u = 0; u < gm_n(acm); ++u)
		for (v = u; v < gm_n(acm); ++v)
			if (gm_mult_edge(acm, u, v))
				fprintf(f, "\t\t %d -- %d [fontcolor = red, label = %.2f];\n",
					u, v, gm_val_edge(acm, u, v));
	fputs("\t}\n}\n", f);
	fclose(f);
	return 0;
}
