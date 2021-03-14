#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_BUFFER 256

typedef struct _REG_FIXO_AUX {
    char ufCode[1];
    char delim;
    char uf[17];
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
    FILE *filePointer;
    char fileName[] = "ibge_municipios_coluna_fixa_sem_cab.txt";
    char currentLine[MAX_LINE_BUFFER], *pointer;
    REG_FIXO_AUX aux;
    IBGE states[27];
    int indexState = 0;
    int countCities = 1;

    filePointer = fopen(fileName, "rt");

    if (filePointer == NULL) {
        printf("O arquivo %s não foi localizado.\n\n", fileName);
        fclose(filePointer);
        return -1;
    }

    while (!feof(filePointer)) {
        char last[17];
        char current[17];

        fgets(currentLine, MAX_LINE_BUFFER, filePointer);

        pointer = currentLine;
        while (*pointer != '\0') {
            if (*pointer == '\n' || *pointer == '\r') {
                *pointer = '\0';
                break;
            }
            pointer++;
        }

        memcpy((void *)&aux, currentLine, sizeof(REG_FIXO_AUX));

        aux.delim = '\0';
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

        if (strcmp(current, last) == 0) { // current equal to last
            if (feof(filePointer)) { // end of file
                strcpy(states[indexState].uf, last);
                states[indexState].quantidadeMunicipio = countCities;
            }

            countCities++;
        } else { // current not equal to last
            strcpy(states[indexState].uf, last);
            if (indexState == 0) {
                states[indexState].quantidadeMunicipio = countCities - 1;
            } else {
                states[indexState].quantidadeMunicipio = countCities;
            }

            indexState++;
            countCities = 1;
        }

        strcpy(last, aux.uf);
    }
    fclose(filePointer);

    for (indexState = 0; indexState < 27; indexState++) {
        printf("Estado: %s - Quantidade de municipios: %d\n", states[indexState].uf, states[indexState].quantidadeMunicipio);
    }

    return 0;
}
