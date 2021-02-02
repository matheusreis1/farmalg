/*
 *  Trabalho 1 - Passos para resolver o sudoku
 *  Autor:
 *  Data:
 * celula: cada quadrado
 * grupo: grupo de [9][9], separado por cor
 */
#include <stdio.h>
#include <string.h>

#define TAMANHO 9

int valoresPossiveis[TAMANHO] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//-------------------------------------------------------------------
// Prototipo das funcões - isso permite que elas sejam colocados
// dentro do arquivo C, em qualquer ordem.
//
void inicializaVetor(int v[], int tam);
void inicializa3Vetor(int v1[], int v2[], int v3[], int tam);
void showMat(int mat[][TAMANHO], int tam);
void showVet(int vetor[], int tam);

// funcoes principais
void valoresAusentesLinha(int jogo[][TAMANHO], int lin, int resultado[], int tam);
void valoresAusentesColuna(int jogo[][TAMANHO], int col, int resultado[], int tam);
void valoresAusentesGrupo(int jogo[][TAMANHO], int grp, int resultado[], int tam);
void valoresPossiveisCelula(int jogo[][TAMANHO], int lin, int col, int resultado[],
                            int linha[], int coluna[], int grupo[], int tam);
void valoresNaoPodemCelula(int jogo[][TAMANHO], int lin, int col, int resultado[],
                            int linha[], int coluna[], int grupo[], int tam);
void numPossibilidades(int jogo[][TAMANHO], int lin, int col, int resultado[],
                            int linha[], int coluna[], int grupo[], int tam);

void valoresAusentesLinha(int jogo[][TAMANHO], int lin, int resultado[], int tam) {
    int i, valorAtual, index, j;
    int vet[TAMANHO];

    inicializaVetor(vet, tam);

    for (i = 0; i < tam; i++) {
        valorAtual = valoresPossiveis[i];
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
        valorAtual = valoresPossiveis[i];

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

/**
 * grupo 1:        | grupo 2:         | grupo 3:         |
 *  - linha 0 - 2  |  - linha: 0 - 2  |  - linha: 0 - 2  |
 *  - coluna 0 - 2 |  - coluna: 3 - 5 |  - coluna: 6 - 8 |
 * -------------------------------------------------------
 * grupo 4:        | grupo 5:         | grupo 6:         |
 *  - linha 3 - 5  |  - linha: 3 - 5  |  - linha: 3 - 5  |
 *  - coluna 0 - 2 |  - coluna: 3 - 5 |  - coluna: 6 - 8 |
 * -------------------------------------------------------
 * grupo 7:        | grupo 8:         | grupo 9:         |
 *  - linha 6 - 8  |  - linha: 6 - 8  |  - linha: 6 - 8  |
 *  - coluna 0 - 2 |  - coluna: 3 - 5 |  - coluna: 6 - 8 |
*/
void valoresAusentesGrupo(int jogo[][TAMANHO], int grp, int resultado[], int tam) {
    printf("grupo %d\n", grp);
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
        valorAtual = valoresPossiveis[i];

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

int solucaoSudoku(int solucao[][TAMANHO], int tam) {
    int possibilidades[TAMANHO][TAMANHO];
    int linha[TAMANHO], coluna[TAMANHO], grupo[TAMANHO], valoresPossiveis[TAMANHO];
    int i, j, k, possib;
    char recomecar = 0, temLacuna = 0;

    do {
        recomecar = 0, temLacuna = 0;

        for (i = 0; i < tam; i++) { // percorre as linhas
            // printf("LINHA %d:\n", i);
            for (j = 0; j < tam; j++) { // percorre as colunas
                // printf("COLUNA %d:\n", j);
                if (solucao[i][j] == 0) { // solucao[i][j] tem o valor de cada celula
                    temLacuna = 1;
                    printf("tem lacuna, valor : %d\n", solucao[i][j]);
                    // avalia as possibilidades

                    inicializaVetor(linha, tam); // inicia 3 vetores: linha, coluna e grupo com tamanho igual a 9
                    inicializaVetor(coluna, tam);
                    inicializaVetor(grupo, tam);
                    inicializaVetor(valoresPossiveis, tam); // inicia 1 vetor: valoresPossiveis com tamanho igual a 9

                    // chama passando a matriz solucao, a linha que o loop esta, vetor linha e tamanho 9
                    // entra na funcao somente se o temLacuna for igual a 1
                    valoresAusentesLinha(solucao, i, &linha, tam);
                    valoresAusentesColuna(solucao, j, &coluna, tam);

                    // grupo (vejam a planilha no moodle)
                    k = ((int)(i/3))*3 + ((int)(j/3)) + 1;
                    valoresAusentesGrupo(solucao, k, &grupo, tam);
                    int z;
                    for (z = 0; z < tam; z++) {
                        /* code */
                        printf("item %d ", grupo[z]);
                    }
                    printf("\n");
                    
                    /*
                    possib = numPossibilidades(solucao, i, j, valoresPossiveis, linha, coluna, grupo, tam);

                    if (possib == 1) {
                        solucao[i][j] = valoresPossiveis[0]; // Observe que é esperado que o valor venha na 1a posicao
                        // esse tipo de quebra do fluxo de execução deve ser usado com cautela.
                        recomecar = 1;
                        break LACO_EXTERNO;
                    } else {
                        possibilidades[i][j] = possib;
                    }
                    */
                } else {
                    printf("nao tem lacuna, valor : %d\n", solucao[i][j]);
                    possibilidades[i][j] = 0;
                }
            }
        }
    } while( recomecar );
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

    // copia os valores de jogoInicial para solucao
    memcpy(solucao, jogoInicial, sizeof(int)*81);

    printf("Configuracao inicial do jogo:\n");
    showMat(solucao, 9);
    // chama a funcao que resolve o problema
    solucaoSudoku(solucao, 9);

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

// void inicializa3Vetor(int v1[], int v2[], int v3[], int tam) {
//     inicializaVetor(v1, tam);
//     inicializaVetor(v2, tam);
//     inicializaVetor(v3, tam);
// }

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
        if (i % 3 == 2) {   // mesma coisa que i%3 == 0
            printf("\n +-----------+-----------+-----------+\n");
        } else {
            printf("\n");
        }
    }
}
