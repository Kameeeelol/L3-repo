#include <stdio.h>

int main() {
    
    FILE *f = fopen("complet-10.dot", "w");
    if (!f) {
        perror("Erreur d'ouverture du fichier");
        return 1;
    }

    fprintf(f, "graph G {\n");

    for (int i = 0; i < 10; i++) {
        fprintf(f, "    %d;\n", i);
    }

    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            fprintf(f, "    %d -- %d;\n", i, j);
        }
    }

    fprintf(f, "}\n");
    fclose(f);
    return 0;
}
