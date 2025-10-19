#include <stdlib.h> /* malloc, free et exit */
#include <stdio.h>
#include <string.h> /* pour memset */
#define TAILLE 50000000UL
#define NUM 10 /* puis 10 avec valgrind */
int main()
{
	int *tab, i;
	for (i = 0; i < NUM; ++i) {
		tab = malloc(TAILLE * sizeof(int));
		if (tab == NULL) {
			perror("malloc");
			exit(-1);
		}
		/* remplir tous les octets de tab avec l'octet i */
		memset(tab, i, TAILLE * sizeof(int));
		printf("Itération numéro %d ok\n", i);
		free(tab);
	}
	printf("Succès ! %d mallocs de taille %zu\n", NUM, TAILLE);
	return 0;
}
