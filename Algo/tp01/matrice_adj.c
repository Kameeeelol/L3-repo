#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ORDRE_MAX 50
int mat[ORDRE_MAX][ORDRE_MAX];

void afficher_mat(int n);
void graphe_complet(int n);
int ecrire_dot(int n, const char *nom_fichier);
void graphe_stable(int n);
void graphe_cycle(int n);
void graphe_biparti_complet(int m, int p);
void graphe_alea(int n, double p);
int lire_dot(const char *nom_fichier);

int main()
{
	graphe_biparti_complet(2, 3);
	char * nom_fichier = "graph_biparti.dot";
	ecrire_dot(5, nom_fichier);
	return 0;
}

void afficher_mat(int n)
{
	int i, j;
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j) {
			printf("%d", mat[i][j]);
			if (j == n - 1)
				printf("\n");
			else
				printf("\t");
		}
	printf("\n");
}

void graphe_complet(int n)
{
	int i, j;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if (i != j){
				mat[i][j] = 1;
			} else { 
				mat[i][j] = 0;
			}
		}
	}
	afficher_mat(n);
}

void graphe_stable(int n)
{
	int i, j;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			mat[i][j] = 0;
		}
	}
	afficher_mat(n);
}


int ecrire_dot(int n, const char *nom_fichier)
{
	FILE *f = fopen(nom_fichier, "w");
    if (!f) {
        perror("Erreur d'ouverture du fichier");
        return 1;
    }
	int symetrique = 1;
    for (int i = 0; i < n && symetrique; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mat[i][j] != mat[j][i]) {
                symetrique = 0;
                break;
            }
        }
    }

    if (symetrique) {
        fprintf(f, "graph {\n");
        for (int i = 0; i < n; i++) {
            fprintf(f, "    %d;\n", i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (mat[i][j] == 1)
                    fprintf(f, "    %d -- %d;\n", i, j);
            }
        }
    } else {
        fprintf(f, "graph {\n");
        for (int i = 0; i < n; i++) {
            fprintf(f, "    %d;\n", i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1)
                    fprintf(f, "    %d -- %d;\n", i, j);
            }
        }
    }
	fprintf(f, "}\n");	
	afficher_mat(n);
	return 0;
}

void graphe_cycle(int n)
{
	int i,j;
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			mat[i][j] = 0;
		}
		int next = (i+1) % n;
		int prev = (i+n-1) % n;
		mat[i][next] = 1;
		mat[i][prev] = 1;
	}
	afficher_mat(n);
}

void graphe_biparti_complet(int m, int p)
{
	int i,j;
	for (i=0; i<m+p; i++){
		for(j=0; j<m+p; j++){
			if ((i<m && j>=m) || (i>=m && j<m)){
				mat[i][j] = 1;
			}else{
				mat[i][j] = 0;
			}
		}
	}
	afficher_mat(m+p);
}

void graphe_alea(int n, double p)
{
	srand(time(NULL));
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                mat[i][j] = 0;
            } else {
                double r = (double)rand() / RAND_MAX;
                mat[i][j] = (r < p) ? 1 : 0;
            }
        }
    }
    afficher_mat(n);
}

int lire_dot(const char *nom_fichier)
{
	FILE *f = fopen(nom_fichier, "r");
    if (!f) {
        perror("Erreur ouverture fichier");
        return -1;
    }

    // Réinitialiser matrice
    for (int i = 0; i < ORDRE_MAX; i++)
        for (int j = 0; j < ORDRE_MAX; j++)
            mat[i][j] = 0;

    char ligne[256];
    int n = 0; // nombre sommets détectés
    int sommet_max = -1;

    // Le graphe doit être non orienté et simple
    // On lit chaque ligne à la recherche des arêtes "i -- j"

    while (fgets(ligne, sizeof(ligne), f)) {
        if (strstr(ligne, "--")) {
            int i, j;
            if (sscanf(ligne, " %d -- %d", &i, &j) == 2) {
                if (i < ORDRE_MAX && j < ORDRE_MAX) {
                    mat[i][j] = 1;
                    mat[j][i] = 1;
                    if (i > sommet_max) sommet_max = i;
                    if (j > sommet_max) sommet_max = j;
                }
            }
        }
    }

    fclose(f);

    n = sommet_max + 1;
    if (n > ORDRE_MAX) {
        fprintf(stderr, "Erreur : nombre de sommets dépasse ORDRE_MAX\n");
        return -2;
    }

    return n;
}
