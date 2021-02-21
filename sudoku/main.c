/*
 *  Trabalho 1 - Passos para resolver o sudoku
 *  Autor: Matheus Henrique Assumpcao dos Reis
 *  Data: 07/02/2021
 */
#include <stdio.h>
#include <string.h>

#define TAMANHO 9

int valoresBase[TAMANHO] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void inicializaVetor(int v[], int tam);
void inicializa3Vetor(int v1[], int v2[], int v3[], int tam);
void showMat(int mat[][TAMANHO], int tam);
void showVet(int vetor[], int tam, char contexto[10]);

void valoresAusentesLinha(int jogo[][TAMANHO], int lin, int resultado[], int tam);
void valoresAusentesColuna(int jogo[][TAMANHO], int col, int resultado[], int tam);
void valoresAusentesGrupo(int jogo[][TAMANHO], int grp, int resultado[], int tam);
void valoresPossiveisCelula(int jogo[][TAMANHO], int lin, int col, int resultado[],
                            int linha[], int coluna[], int grupo[], int tam);
void valoresNaoPodemCelula(int jogo[][TAMANHO], int lin, int col, int resultado[],
                            int linha[], int coluna[], int grupo[], int tam);
int numPossibilidades(int jogo[][TAMANHO], int lin, int col, int resultado[],
                            int linha[], int coluna[], int grupo[], int tam);

void valoresAusentesLinha(int jogo[][TAMANHO], int lin, int resultado[], int tam) {
    int i, valorAtual, index, j;
    int vet[TAMANHO];

    inicializaVetor(vet, tam);

    for (i = 0; i < tam; i++) {
        valorAtual = valoresBase[i];
        for (index = 0; index < TAMANHO; index++) {
            if (jogo[lin][index] == valorAtual) {
                vet[i] = valorAtual;
            }
        }
    }

    for (j = 0; j < tam; j++) {
        if (vet[j] == 0) {
            resultado[j] = j+1;
        }
    }
}

void valoresAusentesColuna(int jogo[][TAMANHO], int col, int resultado[], int tam) {
    int i, valorAtual, index, j;
    int vet[TAMANHO];

    inicializaVetor(vet, tam);

    for (i = 0; i < tam; i++) {
        valorAtual = valoresBase[i];

        for (index = 0; index < TAMANHO; index++) {
            if (jogo[index][col] == valorAtual) {
                vet[i] = valorAtual;
            }
        }
    }

    for (j = 0; j < tam; j++) {
        if (vet[j] == 0) {
            resultado[j] = j+1;
        }
    }
}

void valoresAusentesGrupo(int jogo[][TAMANHO], int grp, int resultado[], int tam) {
    int i, valorAtual, linha, coluna, j;
    int comecoLinha, comecoColuna, limiteLinha, limiteColuna;
    int vet[TAMANHO];

    inicializaVetor(vet, tam);

    switch (grp) {
        case 1:
            comecoLinha = 0;
            limiteLinha = 2;
            comecoColuna = 0;
            limiteColuna = 2;
            break;
        case 2:
            comecoLinha = 0;
            limiteLinha = 2;
            comecoColuna = 3;
            limiteColuna = 5;
            break;
        case 3:
            comecoLinha = 0;
            limiteLinha = 2;
            comecoColuna = 6;
            limiteColuna = 8;
            break;
        case 4:
            comecoLinha = 3;
            limiteLinha = 5;
            comecoColuna = 0;
            limiteColuna = 2;
            break;
        case 5:
            comecoLinha = 3;
            limiteLinha = 5;
            comecoColuna = 3;
            limiteColuna = 5;
            break;
        case 6:
            comecoLinha = 3;
            limiteLinha = 5;
            comecoColuna = 6;
            limiteColuna = 8;
            break;
        case 7:
            comecoLinha = 6;
            limiteLinha = 8;
            comecoColuna = 0;
            limiteColuna = 2;
            break;
        case 8:
            comecoLinha = 6;
            limiteLinha = 8;
            comecoColuna = 3;
            limiteColuna = 5;
            break;
        case 9:
            comecoLinha = 6;
            limiteLinha = 8;
            comecoColuna = 6;
            limiteColuna = 8;
            break;
        default:
            break;
    }

    for (i = 0; i < tam; i++) {
        valorAtual = valoresBase[i];

        for (linha = comecoLinha; linha <= limiteLinha; linha++) {
            for (coluna = comecoColuna; coluna <= limiteColuna; coluna++) {
                if (jogo[linha][coluna] == valorAtual) {
                    vet[i] = valorAtual;
                }
            }
        }
    }
    for (j = 0; j < tam; j++) {
        if (vet[j] == 0) {
            resultado[j] = j+1;
        }
    }

}

void valoresPossiveisCelula(int jogo[][TAMANHO], int lin, int col, int resultado[], int linha[], int coluna[], int grupo[], int tam) {
    int i, z, y;
    
    for (i = 0; i < tam; i++) {
        for (z = 0; z < tam; z++) {
            if (linha[i] == coluna[z] && linha[i] != 0) {
                for (y = 0; y < tam; y++) {
                    if (coluna[z] == grupo[y]) {
                        resultado[i] = valoresBase[i];
                    }
                }
            }
        }
    }
}

void valoresNaoPodemCelula(int jogo[][TAMANHO], int lin, int col, int resultado[], int linha[], int coluna[], int grupo[], int tam) {
    int i, z, y;

    for (i = 0; i < tam; i++) {
        for (z = 0; z < tam; z++) {
            if (linha[i] == coluna[z] && linha[i] != 0) {
                for (y = 0; y < tam; y++) {
                    if (coluna[z] == grupo[y]) {
                        resultado[i] = valoresBase[i];
                    }
                }
            }
        }
    }

    for (i = 0; i < tam; i++) {
        if (resultado[i] != 0) {
            resultado[i] = 0;
        } else {
            resultado[i] = valoresBase[i];
        }
    }
}

int numPossibilidades(int jogo[][TAMANHO], int lin, int col, int resultado[], int linha[], int coluna[], int grupo[], int tam) {
    int i, countPossibilidades;
    countPossibilidades = 0;

    for (i = 0; i < tam; i++) {
        if (resultado[i] != 0)
            ++countPossibilidades;
    }

    return countPossibilidades;
}

int solucaoSudoku(int solucao[][TAMANHO], int tam) {
    int possibilidades[TAMANHO][TAMANHO];
    int linha[TAMANHO], coluna[TAMANHO], grupo[TAMANHO], valoresPossiveis[TAMANHO], valoresNaoPossiveis[TAMANHO];
    int i, j, k, possib, x;
    char recomecar = 0, temLacuna = 0;

    do {
        recomecar = 0, temLacuna = 0;

        for (i = 0; i < tam; i++) {
            for (j = 0; j < tam; j++) {
                if (solucao[i][j] == 0) {
                    temLacuna = 1;

                    inicializaVetor(linha, tam);
                    inicializaVetor(coluna, tam);
                    inicializaVetor(grupo, tam);
                    inicializaVetor(valoresPossiveis, tam);
                    inicializaVetor(valoresNaoPossiveis, tam);

                    valoresAusentesLinha(solucao, i, &linha, tam);
                    valoresAusentesColuna(solucao, j, &coluna, tam);

                    k = ((int)(i/3))*3 + ((int)(j/3)) + 1;
                    valoresAusentesGrupo(solucao, k, &grupo, tam);

                    valoresPossiveisCelula(solucao, i, j, &valoresPossiveis, linha, coluna, grupo, tam);
                    valoresNaoPodemCelula(solucao, i, j, &valoresNaoPossiveis, linha, coluna, grupo, tam);

                    possib = numPossibilidades(solucao, i, j, valoresPossiveis, linha, coluna, grupo, tam);

                    if (possib == 1) {
                        for (x = 0; x < tam; x++) {
                            if (valoresPossiveis[x] != 0 ) {
                                solucao[i][j] = valoresPossiveis[x];
                            }
                        }
                        recomecar = 1;
                    } else {
                        possibilidades[i][j] = possib;
                    }
                } else {
                    possibilidades[i][j] = 0;
                }
            }
        }
    } while (recomecar);
}

int main() {
    int jogoInicial[TAMANHO][TAMANHO] = {
        {9,4,0, 1,0,2, 0,5,8},
        {6,0,0, 0,5,0, 0,0,4},
        {0,0,2, 4,0,3, 1,0,0},
        {0,2,0, 0,0,0, 0,6,0},
        {5,0,8, 0,2,0, 4,0,1},
        {0,6,0, 0,0,0, 0,8,0},
        {0,0,1, 6,0,8, 7,0,0},
        {7,0,0, 0,4,0, 0,0,3},
        {4,3,0, 5,0,9, 0,1,2}
    };
    int solucao[TAMANHO][TAMANHO];
    int linha[TAMANHO], coluna[TAMANHO], grupo[TAMANHO], i, j;

    memcpy(solucao, jogoInicial, sizeof(int)*81);

    printf("Configuracao inicial do jogo:\n");
    showMat(solucao, 9);

    solucaoSudoku(&solucao, 9);

    showMat(solucao, 9);

    return 0;
}

//-------------------------------------------------------------------
// funções auxiliares
void inicializaVetor(int v[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        v[i] = 0;
    }
}

void showVet(int vetor[], int tam, char contexto[10]) {
    int z;
    printf("contexto: %s ", contexto);
    for (z = 0; z < tam; z++) {
        printf("item %d ", vetor[z]);
    }
    printf("\n");
}

void showMat(int mat[][TAMANHO], int tam) {
    int i, j;
    printf("\n +-----------+-----------+-----------+\n");
    for (i = 0; i < tam; i++) {
        printf(" | ");
        for (j = 0; j < tam; j++) {
            if (mat[i][j] > 0) {
                printf(" %d ", mat[i][j]);
            } else {
                printf(" _ ");
            }
            if (j == 2 || j == 5 || j == 8) {
                printf(" | ");
            }
        }
        if (i % 3 == 2) {
            printf("\n +-----------+-----------+-----------+\n");
        } else {
            printf("\n");
        }
    }
}
