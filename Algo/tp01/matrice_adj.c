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
	graphe_complet(10);
	char * nom_fichier = "cmplt_10.dot";
	ecrire_dot(10, nom_fichier);
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
	fprintf(f, "graph  {\n");
	for (int i = 0; i < 10; i++) {
        fprintf(f, "    %d;\n", i);
    }
	int i, j;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if ( mat[i][j] == 1) fprintf(f, "    %d -- %d;\n", i, j);
		}
	}
	afficher_mat(n);
	return 0;
}

void graphe_cycle(int n)
{
}

void graphe_biparti_complet(int m, int p)
{
}

void graphe_alea(int n, double p)
{
}

int lire_dot(const char *nom_fichier)
{
}
