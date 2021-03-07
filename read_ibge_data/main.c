#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_BUFFER 256

typedef struct _REG_FIXO_AUX {
    char uf[18];
    char delim1;
    char mesorregiao[19];
    char delim2;
    char nomeMessorregiao[30];
    char delim3;
    char microrregiao[19];
    char delim4;
    char nomeMicrorregiao[32];
    char delim5;
    char municipio[7];
    char delim6;
    char codigoMunicipio[22];
    char delim7;
    char nomeMunicipio[45];
} REG_FIXO_AUX;

typedef struct _IBGE {
    char uf[18];
    int quantidadeMunicipio;
} IBGE;

int main() {
    FILE *fp;
    char nomeArquivo[] = "ibge_municipios_coluna_fixa_sem_cab.txt";
    char buffer[MAX_LINE_BUFFER], *p;
    REG_FIXO_AUX aux;
    int tam, numreg, indexState = 0;
    IBGE states[27];
    int numCidades = 1;
    int index = 0;

    fp = fopen(nomeArquivo, "rt");

    if (fp == NULL) {
        printf("O arquivo %s não foi localizado.\n\n", nomeArquivo);
        fclose(fp);
        return -1;
    }

    while (!feof(fp)) {
    // while (index < 200) {
        index++;
        char last[18];
        char current[18];

        fgets(buffer, MAX_LINE_BUFFER, fp);

        p = buffer;
        while (*p != '\0') {
            if (*p == '\n' || *p == '\r') {
                *p = '\0';
                break;
            }
            p++;
        }

        memcpy((void *)&aux, buffer, sizeof(REG_FIXO_AUX));

        aux.delim1 = '\0';
        aux.delim2 = '\0';
        aux.delim3 = '\0';
        aux.delim4 = '\0';
        aux.delim5 = '\0';
        aux.delim6 = '\0';
        aux.delim7 = '\0';

        strcpy(current, aux.uf);

        if (strlen(last) == 0) {
            strcpy(last, aux.uf);
        }
        printf("equal %d  %d %d %s %d\n", strcmp(current, last), index, numCidades, current, indexState);

        if (strcmp(current, last) == 0) {
            if (feof(fp)) {
                strcpy(states[indexState].uf, last);
                states[indexState].quantidadeMunicipio = numCidades;
            }
            numCidades++;
        } else {
            strcpy(states[indexState].uf, last);
            if (indexState == 0) {
                states[indexState].quantidadeMunicipio = numCidades - 1;
            } else {
                states[indexState].quantidadeMunicipio = numCidades;
            }

            indexState++;
            numCidades = 1;
        }

        strcpy(last, aux.uf);
    }
    fclose(fp);

    int i = 0;
    while (i < 27) {
        puts(states[i].uf);
        printf("Num: %d\n", states[i].quantidadeMunicipio);
        i++;
    }

    return 0;
}
