#include <stdio.h>

int main() {
    int valores[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int vetor[9] = { 3, 0, 6, 5, 0, 8, 4, 0, 0 };
    int i, j;

    for (i = 0; i < 9; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    for (i = 0; i < 9; i++) {
        printf("%d:\n", vetor[i]);
        for (j = 0; j < 9; j++) {
            printf("%d ", valores[i]);
        }
        printf("\n");
    }
    printf("\n");
}

/*
void valoresNaoPodemCelula(int jogo[][TAMANHO], int lin, int col, int resultado[], int linha[], int coluna[], int grupo[], int tam) {
    int i, z, y;
    
    for (i = 0; i < tam; i++) {
        for (z = 0; z < tam; z++) {
            if (linha[i] != coluna[z]) {
                for (y = 0; y < tam; y++) {
                    if (coluna[z] != grupo[y]) {
                        resultado[i] = valoresBase[i];
                    }
                }
            }
        }
    }
    showVet(resultado, tam, "nopossi");
}
void valoresPossiveisCelula(int jogo[][TAMANHO], int lin, int col, int resultado[], int linha[], int coluna[], int grupo[], int tam) {
    int i, z, y, j;
    
    for (i = 0; i < tam; i++) {
        // printf("item linha %d ", linha[i]);
        for (z = 0; z < tam; z++) {
            // printf("item coluna %d ", coluna[z]);
            if (linha[i] == coluna[z] && linha[i] != 0) {
                for (y = 0; y < tam; y++) {
                    if (coluna[z] == grupo[y]) {
                        // printf("item grupo %d - i: %d", grupo[y], valoresBase[i]);
                        resultado[i] = valoresBase[i];
                    }
                }
                // printf("\n");
            }
        }
        // printf("\n");
    }
    // printf("\n");
    showVet(resultado, tam, "possi");
}
*/
