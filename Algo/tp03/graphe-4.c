/**
 * \file graphe-4.c
 * \brief Représentation des graphes par liste de successeurs
 * \version 1
 * \date lundi 4 novembre 2019
 * \authors Pierre Rousselin, Antoine Rozenknop, Sophie Toulouse
*/
#include "graphe-4.h"

#include <stdio.h>
#include <stdlib.h>

/* __________________________________ Accesseurs sur les maillons */
msuc *msuc_suivant(msuc *m)
{
	return m->suivant;
}

int msuc_sommet(msuc *m)
{
	return m->sommet;
}

double msuc_valeur(msuc *m)
{
	return m->valeur;
}


/* __________________________________ Initialisation / Destruction */

int graphe_stable(graphe* g, int n, int est_or)
{
    g->n = n;
	g->m = 0;
	g->est_or = est_or;
	g->tab_sucs = malloc(n * sizeof(msuc*));
	if( ! g->tab_sucs ) return EXIT_FAILURE;
	for(int i = 0; i<n; i++) g->tab_sucs[i] = NULL;
    return 0;
}

void graphe_detruire(graphe *g)
{
	for (int i=0; i<g->n; i++){
		msuc *courant = g->tab_sucs[i];
		while (courant != NULL){
			msuc *suivant = courant->suivant;
			free(courant);
			courant = suivant;
		}
	}
	free(g->tab_sucs);
}
/* __________________________________ Ajout / Suppression d'arêtes */

/* Attention :
 * Si le graphe est orienté, utiliser les fonctions _arc
 * Si le graphe est non orienté, utiliser les fonction _arete
 */

int graphe_ajouter_arc(graphe *g, int v, int w, double val)
{
    msuc *m = malloc(sizeof(msuc));
	if ( m == NULL ) return -1;
	printf("l'initialisation du maillon est faite parfaitement\n");
	m->sommet = w; 
	printf("sommet : %d\n", m->sommet);
	m->valeur = val;
	printf("valeur : %f\n", m->valeur);
	m->suivant = g->tab_sucs[v];
	g->tab_sucs[v] = m;
	g->m++;
	return 0;
}

int graphe_ajouter_arete(graphe* g, int v, int w, double val)
{
    if ( graphe_ajouter_arc(g,v,w,val) == -1) return -1;
	if ( graphe_ajouter_arc(g,w,v,val) == -1) return -1;
	g->m--;
	return 0;
}

int graphe_supprimer_arc(graphe *g, int v, int w, double val)
{
    /* TODO */
	return -1;
}


int graphe_supprimer_arete(graphe* g, int v, int w, double val)
{
    /* TODO */
	return 0;
}

/* ______________________________________ Accesseurs en lecture */
int graphe_est_or(graphe *g)
{
	return g->est_or;
}

int graphe_get_n(graphe* g)
{
	return g->n;
}

int graphe_get_m(graphe* g)
{
	return g->m;
}

msuc *graphe_get_prem_msuc(graphe *g, int v)
{
    return g->tab_sucs[v];
}

/* NE PAS ACCÉDER DIRECTEMENT AUX CHAMPS EN-DESSOUS DE CETTE LIGNE */

int graphe_get_multiplicite_arc(graphe* g, int v, int w)
{
	int nb = 1;
	msuc *courant = graphe_get_prem_msuc(g,v);
	while (courant != NULL){
		if( msuc_sommet(courant) == w) nb++;
		courant = msuc_suivant(courant);
	}
	return nb;
}

int graphe_get_multiplicite_arete(graphe* g, int v, int w)
{
	return graphe_get_multiplicite_arc(g,v,w);
}

int graphe_get_degre_sortant(graphe* g, int v)
{
    int d = 0;
	msuc *courant = graphe_get_prem_msuc(g,v);
	while ( courant != NULL){
		d++;
		courant = msuc_suivant(courant);
	}
	return d;
}

int graphe_get_degre_entrant(graphe* g, int w)
{
    int d = 0;
    for (int i = 0; i < g->n; i++) {
        msuc *courant = graphe_get_prem_msuc(g, i);
        while (courant != NULL) {
            if (msuc_sommet(courant) == w) d++;
            courant = msuc_suivant(courant);
        }
    }
    return d;
}

int graphe_get_degre(graphe *g, int v)
{
    if (!g->est_or)
        return graphe_get_degre_sortant(g, v);

    return graphe_get_degre_sortant(g, v) + graphe_get_degre_entrant(g, v);
}

/* ______________________________________ Entrées / Sorties */

void graphe_afficher(graphe* g)
{
	int v, w;
	msuc *m;
	int n = graphe_get_n(g);
	printf("graphe %s d'ordre %d à %d aretes :\n",
		graphe_est_or(g) ? "orienté" : "non orienté",
		graphe_get_n(g), graphe_get_m(g));
	for (v = 0; v < n; ++v) {
		puts("successeurs de v : ");
		for (m = graphe_get_prem_msuc(g, v); m; m = msuc_suivant(m)) {
			w = msuc_sommet(m);
			printf("%2d, ", w);
		}
		puts("");
	}
}

int graphe_ecrire_dot(graphe *g, char *nom_fichier, int ecrire_valeurs)
{
	int u;
	int n = graphe_get_n(g);
	FILE *f = fopen(nom_fichier, "w");
	int est_or = graphe_est_or(g);
	msuc *m;
	if (!f) { perror("fopen"); return -1; }

	if (est_or)
		fputs("digraph {\n", f);
	else
		fputs("graph {\n", f);

	for (u = 0; u < n; ++u)
		fprintf(f, "\t%d;\n", u);
	fputs("\n", f);

	for (u = 0; u < n; ++u)
		for (m = graphe_get_prem_msuc(g, u); m; m = msuc_suivant(m)) {
			int v = msuc_sommet(m);
			double val = msuc_valeur(m);
			if (!est_or && v < u) /* arête déjà rencontrée */
				continue;
			fprintf(f, "\t%d -%c %d ",
					u, est_or ? '>' : '-', v);
			if (ecrire_valeurs)
				fprintf(f, " [label = %.2f]", val);
			fprintf(f, ";\n");
		}
	fputs("}\n", f);

	fclose(f);
	return 0;
}

/* ______________________________________ Autres fonctions d'initialisation */

int graphe_complet(graphe* g, int n, int est_or)
{
	int v, w;
	if (graphe_stable(g, n, est_or) < 0)
		return -1;
	for (v = 0; v < graphe_get_n(g); ++v)
		if (!est_or) {
			for (w = v + 1; w < graphe_get_n(g); ++w)
				if (graphe_ajouter_arete(g, v, w, 1.) < 0) {
					graphe_detruire(g);
					return -1;
				}
		} else {
			for (w = 0; w < graphe_get_n(g); ++w)
				if (graphe_ajouter_arc(g, v, w, 1.) < 0) {
					graphe_detruire(g);
					return -1;
				}
		}
	return 0;
}

int graphe_aleatoire(graphe* g, int n, double p, int est_or)
{
	int v, w;
	if (n < 0)
		return -2;
	if (p < 0 || p > 1)
		return -3;
	if (graphe_stable(g, n, est_or) < 0)
		return -1;
	if (!est_or) {
		for (v = 0; v < graphe_get_n(g); ++v)
			for (w = v; w < graphe_get_n(g); ++w)
				if ((double) rand()/RAND_MAX < p)
					if (graphe_ajouter_arete(g, v, w, 0.) < 0) {
						graphe_detruire(g);
						return -1;
					}
	} else {
		for (v = 0; v < graphe_get_n(g); ++v)
			for (w = 0; w < graphe_get_n(g); ++w)
				if ((double) rand()/RAND_MAX < p)
					if ( graphe_ajouter_arc(g, v, w, 0.) < 0) {
						graphe_detruire(g);
						return -1;
					}
	}
	return 0;
}

int graphe_aleatoire_multi(graphe* g, int n, double p, int est_or)
{
	int v, w;
	if (n < 0)
		return -2;
	if (p < 0 || p >= 1)
		return -3;
	if (graphe_stable(g, n, est_or) < 0)
		return -1;
	if (!est_or) {
		for (v = 0; v < graphe_get_n(g); ++v)
			for (w = v; w < graphe_get_n(g); ++w)
				while ((double) rand()/RAND_MAX < p)
					if (graphe_ajouter_arete(g, v, w, 0.) < 0) {
						graphe_detruire(g);
						return -1;
					}
	} else {
		for (v = 0; v < graphe_get_n(g); ++v)
			for (w = 0; w < graphe_get_n(g); ++w)
				while ((double) rand()/RAND_MAX < p)
					if (graphe_ajouter_arc(g, v, w, 0.) < 0) {
						graphe_detruire(g);
						return -1;
					}
	}
	return 0;
}
