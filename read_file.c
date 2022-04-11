#include "header.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX_LINES 1000
#define MAX_LINE_SIZE 1000
malos* getArray(char *archivo_csv){
    malos arreglo[MAX_LINES];
    int i = 0;
    FILE *fp = fopen(archivo_csv, "r");
    char line[MAX_LINE_SIZE];
    char *token;
    fgets(line, MAX_LINE_SIZE, fp);
    // Leemos linea a linea
    while(fgets(line, MAX_LINE_SIZE, fp) != NULL) // el arreglo line se rellena con los caracteres de la linea
    {
        // strtok(line, ",") entrega el substring desde el comienzo hasta la primera aparicion del delimitador "," (excluyendolo)
        // Copiamos el substring al campo palabra de la estructura
        strcpy(arreglo[i].first_name, strtok(line, ","));
        // Obtenemos el siguiente substring
        token = strtok(NULL, ",");
        arreglo[i].danger_category = atoi(token); // atoi convierte un string a int

        token = strtok(NULL, ",");
        if(strcmp(token, "\n") == 0) // caso que no hay int
            arreglo[i].attack_prob = 0;
        else
            arreglo[i].attack_prob = atof(token); // atoi convierte un string a int

        i++;

    }

    // Mostramos el arreglo generado
    // En este punto la variable i contiene la cantidad de elementos en el arreglo
    for(int j=0; j < i; j++)
        printf("Entrada %d:\nnombre: %s\ndanger_category: %d\nattack_prob: %f\n", j, arreglo[j].first_name, arreglo[j].danger_category,arreglo[j].attack_prob);
    return arreglo;
}